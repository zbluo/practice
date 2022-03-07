//
// Created by Zhong Bing on 2020-02-26.
//

#ifndef DESIGNSTRATEGY_OBJECTPOOL_H
#define DESIGNSTRATEGY_OBJECTPOOL_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <stack>

template<class T>
class SharedPool1
{
private:
    std::vector<std::shared_ptr<T>> pool_;

public:
    SharedPool1(){}
    virtual ~SharedPool1(){}

    void add(std::shared_ptr<T> t) {
        pool_.push_back(std::move(t));
    }

    std::shared_ptr<T> acquire() {
        assert(!empty());
        return *std::find_if(pool_.begin(), pool_.end(), [](const std::shared_ptr<T>& i){return i.use_count() == 1;});
    }

    bool empty() const {
        return std::none_of(pool_.begin(), pool_.end(), [](const std::shared_ptr<T>& i){return i.use_count() == 1;});
    }
};

template<class T>
class SharedPoolParent
{
public:
    SharedPoolParent(){};
    ~SharedPoolParent(){};
};

template<typename T>
class return_to_pool
{
    std::weak_ptr<SharedPoolParent<T>> pool;

public:
    return_to_pool(const std::shared_ptr<SharedPoolParent<T>>& sp) : pool(sp) { }

    void operator()(T* p) const
    {
        if (auto sp = pool.lock())
        {
            try {
                sp->add(std::unique_ptr<T>(p));
                return;
            } catch (const std::bad_alloc&) {
            }
        }
        std::default_delete<T>{}(p);
    }
};

template<typename T>
void back_to_pool(T *p) {
    std::default_delete<T>{}(p);
    return;
}

template <class T>
class SharedPool : std::enable_shared_from_this<SharedPool<T>>, SharedPoolParent<T>
{
public:
    using ptr_type = std::unique_ptr<T, std::function<void(T*)>>;
    SharedPool(){};
    ~SharedPool(){};

    void add(std::unique_ptr<T> p) {
        pool_.push(std::move(p));
    }

    ptr_type acquire()
    {
        if (pool_.empty())
            throw std::logic_error("pool closed");
        ptr_type tmp;
        tmp = move(pool_.top());
        pool_.pop();
        return tmp;
    }
    bool empty() const {
        return pool_.empty();
    }

    size_t size() const {
        return pool_.size();
    }
private:
    std::stack<std::unique_ptr<T> > pool_;
};

// SharedPool must be owned by a shared_ptr for enable_shared_from_this to work
auto pool = std::make_shared<SharedPool<int>>();
#endif //DESIGNSTRATEGY_OBJECTPOOL_H
