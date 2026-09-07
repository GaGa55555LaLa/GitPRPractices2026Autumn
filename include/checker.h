#pragma once
#include <functional>
#include <string>
#include <vector>

using Vec = std::vector<std::pair<std::string, std::string>>;
bool isGoodVector(std::size_t E, const Vec &V);
std::size_t HashString(const std::string &S);

class HookRegistry {
  public:
    using HookFn = std::function<bool()>;

    static HookRegistry &instance() {
        static HookRegistry reg;
        return reg;
    }

    void add(HookFn fn) {
        hooks.push_back(std::move(fn));
    }

    bool runAll() {
        for (const auto &fn : hooks) {
            if (fn) {
                if (!fn())
                    return false;
            }
        }
        return true;
    }

  private:
    HookRegistry() = default;
    std::vector<HookFn> hooks;
};

struct AutoHookRegister {
    AutoHookRegister(HookRegistry::HookFn fn) {
        HookRegistry::instance().add(std::move(fn));
    }
};

#define CONCAT_IMPL(x, y) x##y
#define CONCAT(x, y) CONCAT_IMPL(x, y)

#define REGISTER_HOOK(fn) static AutoHookRegister CONCAT(_auto_hook_reg_, __LINE__)(fn);
