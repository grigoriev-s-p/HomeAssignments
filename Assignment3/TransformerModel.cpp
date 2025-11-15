#include "TransformerModel.h"
TransformerModel::TransformerModel(std::string model) : _model(model) {};
std::string TransformerModel::getModel() {
    return _model;
}

void TransformerModel::setModel(std::string newModel) {
    _model = newModel;
}
