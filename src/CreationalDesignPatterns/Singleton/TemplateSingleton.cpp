#include <iostream>

template<typename T>
class Singleton
    {
    public:
        static auto getInstance() -> Singleton<T>*;
        
        Singleton(const Singleton<T>&) = delete;
        Singleton(Singleton<T>&&)      = delete;
        auto operator=(const Singleton<T>&) -> Singleton<T>& = delete;
        auto operator=(Singleton<T>&&)      -> Singleton<T>& = delete;

        auto getData() const -> const T&;
        auto setData(const T &data) -> void;

    private:
        Singleton() = default;
        static Singleton<T>* instance;
        T data;
    };

template<typename T>
Singleton<T> *Singleton<T>::instance = nullptr;

template<typename T>
auto Singleton<T>::getInstance()
    -> Singleton<T>*
    {
    if (!instance)
        instance = new Singleton<T>();
    return instance;
    }

template<typename T>
auto Singleton<T>::getData() const
    -> const T&
    {
    return this->data;
    }

template<typename T>
auto Singleton<T>::setData(const T &data)
    -> void
    {
    this->data = data;
    }

int main()
    {
    for(int iter = 0; iter < 10; ++iter) 
        {
        Singleton<int>::getInstance()->setData(iter);
        std::cout << Singleton<int>::getInstance() << '\n';
        }
    std::cout << "Data: " << Singleton<int>::getInstance()->getData() << '\n';
    return 0;
    }