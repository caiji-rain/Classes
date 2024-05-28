#include "LogoScene.h"
#include "StartScene.h"

LogoScene* LogoScene::create()
{
    LogoScene* ret = new LogoScene();
    if(ret && ret->init())
    {
        ret->autorelease();
    }else
    {
        delete ret;
        ret = nullptr;
    }
    
    return ret;
}

bool LogoScene::init()
{
    if(!Scene::init())
    {
        return false;
    }
    // 创建白色背景
    LayerColor* layerColor = LayerColor::create(Color4B::WHITE);
    this->addChild(layerColor);
    
    // 创建Logo图片背景
    Sprite* logo = Sprite::create("fslogo.png");
    logo->setPosition(Vec2(480,320));
    this->addChild(logo);


	scheduleOnce([&](float dt)
	{
		Director* director = Director::getInstance();
		StartScene* startscene = StartScene::create();
		TransitionCrossFade* cross = TransitionCrossFade::create(1.f, startscene);
		director->replaceScene(cross);
	}, 1.f, "Start"
	);
	


    return true;
}
