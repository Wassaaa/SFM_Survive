{
  description = "a developement environment for SFML framework game";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs =
    {
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
            # 1. Core build tools
            cmake # The build system generator, as required by the README
            pkg-config # Helps build tools find libraries
            gcc # A C++ compiler (you could also use `clang`)
            gdb # The GNU Debugger, very useful for C++

            # 2. SFML Dependencies (translated from the README's apt list)
            # These are for windowing, graphics, and input via X11 (using XWayland)
            xorg.libX11
            xorg.libXrandr
            xorg.libXcursor
            udev

            # General media and font libraries
            freetype
            openalSoft # For audio
            libvorbis # For .ogg audio format
            flac # For .flac audio format

            # Graphics libraries
            mesa # Provides OpenGL drivers (libGL, libEGL)
          ];
          shellHook = ''
            echo "SFML development environment loaded."
            echo "Run 'cmake -B build' and 'cmake --build build' to compile."
          '';
        };
      }
    );
}
