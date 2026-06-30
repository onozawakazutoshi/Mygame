#include "TitleChange.h"

void TitleChange::Initialize() {
	uint32_t tex = TextureManager::Load("Sprit/white1x1.png");

	titleChange_ = Sprite::Create(tex, {640.0f, 360.0f}, {0, 0, 0, 0}, {0.5f, 0.5f}, false, false);
	titleChange_->SetSize({1280, 720});
	titletime_ = true;
	gametime_ = false;
}
void TitleChange::Update() { 
	if (alpha_ < 1.0f&& titletime_) {
		alpha_ += 0.01f;
	}else if (alpha_ > 0.0f && !titletime_) {
		alpha_ -= 0.01f;
	} else {
		titletime_ = false;
		gametime_ = true;
	}
	titleChange_->SetColor({0,0,0,alpha_});


}
void TitleChange::Draw(ID3D12GraphicsCommandList* commandList) {
	Sprite::PreDraw(commandList);
	titleChange_->Draw();
	Sprite::PostDraw();
}