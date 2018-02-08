#include "stdafx.h"

void NetworkTransformToBytes(char bytes_temp[1 + 6 * sizeof(float)], sfNetworkTransform _tr)
{
	char datas[1 + 6 * sizeof(float)];
	char* floatDatareader = datas;

	char tempChar = _tr.GetNetworkID();
	memcpy(floatDatareader, &tempChar, sizeof(char));
	floatDatareader += sizeof(char);
	float tempFloat = _tr.GetPos().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _tr.GetPos().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _tr.GetRot().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _tr.GetRot().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _tr.GetScale().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _tr.GetScale().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));

	memcpy(bytes_temp, &datas, 1 + 6 * sizeof(float));
}
void BytesToNetworkTransform(sfNetworkTransform* _tr, char bytes_temp[1 + 6 * sizeof(float)])
{
	char* floatDatareader = bytes_temp;
	sf::Vector2f tempV2;

	floatDatareader += sizeof(char);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->SetPos(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->SetRot(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->SetScale(tempV2);
}

void NetworkButtonToBytes(char bytes_temp[1 + 6 * sizeof(float)], sfNetworkButton _button)
{
	char datas[1 + 6 * sizeof(float)];
	char* floatDatareader = datas;

	char tempChar = _button.GetNetworkID();
	memcpy(floatDatareader, &tempChar, sizeof(char));
	floatDatareader += sizeof(char);
	float tempFloat = _button.GetPos().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _button.GetPos().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _button.GetRot().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _button.GetRot().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _button.GetScale().x;
	memcpy(floatDatareader, &tempFloat, sizeof(float));
	floatDatareader += sizeof(float);
	tempFloat = _button.GetScale().y;
	memcpy(floatDatareader, &tempFloat, sizeof(float));

	memcpy(bytes_temp, &datas, 1 + 6 * sizeof(float));
}
void BytesToNetworkButton(sfNetworkButton* _button, char bytes_temp[1 + 6 * sizeof(float)])
{
	char* floatDatareader = bytes_temp;
	sf::Vector2f tempV2;

	floatDatareader += sizeof(char);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->SetPos(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->SetRot(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->SetScale(tempV2);
}
