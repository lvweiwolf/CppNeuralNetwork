#ifndef _LAYER_H
#define _LAYER_H

class Layer
{
public:
    Layer(size_t input, size_t output);
    Layer(size_t input, size_t output, activation = "sigmoid");

    virtual ~Layer();

private:
};

#endif // _LAYER_H