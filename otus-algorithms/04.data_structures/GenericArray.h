//
// Created by Aleksey Leshchankin on 11.11.2022.
//

template <typename T>
class GenericArray {
public:
    GenericArray() {};
    ~GenericArray() {};

    // -- Main Interface --
    unsigned int Size() const;
    void Add (const T item, unsigned int index);
    T Remove (unsigned int index);

    // -- Enablers --
    void Resize ();

private:
    unsigned int *arr;
    unsigned int current_size;
    unsigned int capacity;
};