#include "GameScene.h"

USING_NS_CC;

Scene* Game::createScene()
{
    auto scene = Scene::createWithPhysics();

    /* 重力設定 */
    Vect gravity;
    gravity.setPoint(0, -50);
    scene->getPhysicsWorld()->setGravity(gravity);
    scene->getPhysicsWorld()->setSpeed(6.0f);

    /* デバッグモード */
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = Game::create();
    scene->addChild(layer);

    return scene;
}

bool Game::init()
{
    /* 初期化 */
    if ( !Layer::init() ) return false;

    /* 画面サイズサイズを取得 */
    auto window_size = Director::getInstance()->getWinSize();

    /* 地面の反発係数と摩擦係数 */
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.restitution = 0.0f;
    material.friction = 0.0f;

    /* 地面 */
    auto wall = Sprite::create();
    wall->setTextureRect(Rect(0,0,1000,100));
    auto pWall = PhysicsBody::createBox(wall->getContentSize(), material);

    /* 重力干渉を受けるか */
    pWall->setDynamic(false);

    /* 回転させるか */
    pWall->setRotationEnable(false);

    wall->setPhysicsBody(pWall);
    wall->setPosition(150, 0);
    wall->setColor(Color3B(255,255,255));
    wall->setRotation(10.0f);

    addChild(wall);

    /* ボール */
    auto ball = Sprite::create();
    ball->setPosition(20, 300);
    ball->setColor(Color3B(255,255,255));
    auto pBall = PhysicsBody::createCircle(10.0f);
    pBall->setDynamic(true);
    pBall->setRotationEnable(true);
    ball->setPhysicsBody(pBall);
    addChild(ball);

    return true;
}