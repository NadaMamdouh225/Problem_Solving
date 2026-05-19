class Foo {
public:

    binary_semaphore s1{0};
    binary_semaphore s2{0};
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        s1.release();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        s1.acquire();
        printSecond();
        s2.release();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        s2.acquire();
        printThird();
    
    }
};
