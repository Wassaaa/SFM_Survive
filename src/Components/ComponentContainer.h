#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>
#include "Component.h"

class ComponentContainer
{
public:
    template <typename T, typename... Args> T &addComponent(Args &&...args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
        auto component = std::make_shared<T>(std::forward<Args>(args)...);
        T &componentRef = *component;
        components[typeid(T)] = std::move(component);
        return componentRef;
    }

    template <typename T> T *getComponent()
    {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
        auto it = components.find(typeid(T));
        return it != components.end() ? static_cast<T *>(it->second.get()) : nullptr;
    }

    template <typename T> const T *getComponent() const
    {
        static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
        auto it = components.find(typeid(T));
        return it != components.end() ? static_cast<const T *>(it->second.get()) : nullptr;
    }

protected:
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components;
};
