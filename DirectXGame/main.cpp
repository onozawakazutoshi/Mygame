#include <Windows.h>
#include <KamataEngine.h>
#include"GameScene.h"
#include "Title.h"
#include "TitleChange.h"
#include "c.h"
#include "SceneManager.h"
	
using namespace KamataEngine;

GameScene* gameScene = new GameScene();
Title* title = new Title();
TitleChange* titleChange = new TitleChange();
c* C = new c();
SceneManager* manager = new SceneManager();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize();
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	gameScene->Initialize();
	title->Initialize();
	titleChange->Initialize();
	int switch_on = 0;
	C->Initialize();

	while (true) {
		if (KamataEngine::Update()) {

			break;
		}
		//gameScene->Update();

		
		manager->Update();

		dxCommon->PreDraw();

		manager->Draw(dxCommon->GetCommandList());

		dxCommon->PostDraw();
	
		
		
	}

	
	KamataEngine::Finalize();

	return 0;
}
