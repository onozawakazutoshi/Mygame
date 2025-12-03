#pragma once
#include "KamataEngine.h"

#include <iostream>

using namespace KamataEngine;



class Title {
public:
	void Initialize();
	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

	void Acc();

	bool IsGameChange() { return gemeChange_; }

private:
	Sprite* title_;
	Sprite* ra;
	Sprite* bi;
	Sprite* de;
	Sprite* nn;
	Sprite* su;

	float alpha_ = 0.0f;

	int titlemode_ = 0;
	Input* input_;

	int sleeptime_ = 60;

	Vector2 bipos_ = {440.0f, 360.0f};// 位置 (m)
	Vector2 vel{0.0f, 9.0f};   // 速度 (m/s)
	Vector2 acc{0.0f, 9.81f}; // 加速度 (m/s^2) 例: 重力

	bool bioverflage_ = false;//座標1000を超えたどうか

	bool gemeChange_ = false;

};
