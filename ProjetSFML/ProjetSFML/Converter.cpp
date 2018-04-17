#include "stdafx.h"


char* NetworkTransformToBytes(sfNetworkTransform _tr)
{
	char* datas = new char[1 + 6 * sizeof(float)];
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

	return datas;
}
void BytesToNetworkTransform(sfNetworkTransform* _tr, char bytes_temp[1 + 6 * sizeof(float)])
{
	char* floatDatareader = bytes_temp;
	sf::Vector2f tempV2;

	_tr->NetworkIdentity::Obj_mtx->lock();
	floatDatareader += sizeof(char);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->sfTransform::SetPos(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->sfTransform::SetRot(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_tr->sfTransform::SetScale(tempV2);
	_tr->NetworkIdentity::Obj_mtx->unlock();
}

char* NetworkButtonToBytes(sfNetworkButton _button)
{
	char* datas = new char[1 + 6 * sizeof(float)];
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

	return datas;
}
void BytesToNetworkButton(sfNetworkButton* _button, char bytes_temp[1 + 6 * sizeof(float)])
{
	char* floatDatareader = bytes_temp;
	sf::Vector2f tempV2;

	_button->NetworkIdentity::Obj_mtx->lock();
	floatDatareader += sizeof(char);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->sfTransform::SetPos(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->sfTransform::SetRot(tempV2);

	floatDatareader += sizeof(float);
	tempV2.x = *((float*)floatDatareader);
	floatDatareader += sizeof(float);
	tempV2.y = *((float*)floatDatareader);
	_button->sfTransform::SetScale(tempV2);
	_button->NetworkIdentity::Obj_mtx->unlock();
}
