{
  description = "a developement environment for SFML framework game";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            # Core build tools
            cmake
            pkg-config
            gcc
            gdb

            # SFML Dependencies

            # Audio
            flac
            libvorbis
            openalSoft

            # Graphics & Windowing
            freetype
            glew
            libjpeg
            mesa
            udev

            # X11 Libraries
            xorg.libX11
            xorg.libXcursor
            xorg.libXrandr
            xorg.libXrender
            xorg.xcbutilimage
          ];
          shellHook = ''
            echo "SFML development environment loaded."
            echo "Run 'cmake -B build' and 'cmake --build build' to compile."
          '';
        };
      }
    );
}
