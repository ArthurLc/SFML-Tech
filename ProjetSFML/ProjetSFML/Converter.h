#ifndef CONVERTER_H
#define CONVERTER_H

inline void FloatToBytes(char bytes_temp[4], float float_variable) { memcpy(bytes_temp, &float_variable, sizeof float_variable); }
inline void BytesToFloat(float* float_variable, char bytes_temp[4]) { memcpy(float_variable, bytes_temp, sizeof float_variable); }

void NetworkTransformToBytes(char bytes_temp[1 + 6 * sizeof(float)], sfNetworkTransform _tr);
void BytesToNetworkTransform(sfNetworkTransform* _tr, char bytes_temp[1 + 6 * sizeof(float)]);

void NetworkButtonToBytes(char bytes_temp[1 + 6 * sizeof(float)], sfNetworkButton _button);
void BytesToNetworkButton(sfNetworkButton* _button, char bytes_temp[1 + 6 * sizeof(float)]);

#endif
