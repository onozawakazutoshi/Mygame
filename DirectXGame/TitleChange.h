#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;
class TitleChange {
	
public:
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

	bool IsTitleChange() { return titletime_; }
	bool IsGameChange() { return gametime_; }

private:
	Sprite* titleChange_;

	float alpha_ = 0.0f;

	bool titletime_ = false;
	bool gametime_ = false;

};
