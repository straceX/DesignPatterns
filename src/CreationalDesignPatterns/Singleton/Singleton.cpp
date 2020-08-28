#include <iostream>

class Singleton
    {
    public:
        static auto getInstance() noexcept -> Singleton*;
        
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&)      = delete;
        auto operator=(const Singleton&) -> Singleton& = delete;
        auto operator=(Singleton&&)      -> Singleton& = delete;

    private:
        Singleton() = default;
        static Singleton *instance;
    };

Singleton *Singleton::instance = nullptr;

auto Singleton::getInstance() noexcept
    -> Singleton*
    {
    if (!instance)
        instance = new Singleton();
    return instance;
    }

int main()
    {
    for(int iter = 0; iter < 10; ++iter) 
        std::cout << Singleton::getInstance() << '\n';
    return 0;
    }