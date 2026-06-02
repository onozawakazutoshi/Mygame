#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;
class WorldTransformEx : 
	public KamataEngine::WorldTransform {

public:
	// Affine変換行列の生成と定数バッファへの転送を行う
	void UpdateMatrix();

	//Matrix4x4 MakeAffinMatrix(Vector3& S, Vector3& R, Vector3& T);

	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	Vector3 Transform(Vector3 vector, Matrix4x4 matrix);

	Matrix4x4 MAkeTranslateMatrix(Vector3& vector3);

	Matrix4x4 MAkeScaleMatrix(Vector3& vector3);

	/*Matrix4x4 MakeRotateXMatrix(Vector3& vector);

	Matrix4x4 MakeRotateYMatrix(Vector3& vector);

	Matrix4x4 MakeRotateZMatrix(Vector3& vector);*/

	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Inverse(Matrix4x4& m);
	Vector3 Nomaliz(Vector3& v1);

	// Affine変換行列の生成
	Matrix4x4 MakeAffinMatrix();
};
