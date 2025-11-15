#ifndef TRANSFORMERMODEL
#define TRANSFORMERMODEL
#include <string>
class TransformerModel {
public:
    TransformerModel(std::string model);
    std::string getModel();
    void setModel(std::string newModel);
private:
    std::string _model;
};
#endif
