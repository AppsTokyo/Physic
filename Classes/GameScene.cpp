#include "GameScene.h"

USING_NS_CC;

Scene* Game::createScene()
{
    auto scene = Scene::createWithPhysics();

    /* �d�͐ݒ� */
    Vect gravity;
    gravity.setPoint(0, -50);
    scene->getPhysicsWorld()->setGravity(gravity);
    scene->getPhysicsWorld()->setSpeed(6.0f);

    /* �f�o�b�O���[�h */
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = Game::create();
    scene->addChild(layer);

    return scene;
}

bool Game::init()
{
    /* ������ */
    if ( !Layer::init() ) return false;

    /* ��ʃT�C�Y�T�C�Y���擾 */
    auto window_size = Director::getInstance()->getWinSize();

    /* �n�ʂ̔����W���Ɩ��C�W�� */
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.restitution = 0.0f;
    material.friction = 0.0f;

    /* �n�� */
    auto wall = Sprite::create();
    wall->setTextureRect(Rect(0,0,1000,100));
    auto pWall = PhysicsBody::createBox(wall->getContentSize(), material);

    /* �d�͊����󂯂邩 */
    pWall->setDynamic(false);

    /* ��]�����邩 */
    pWall->setRotationEnable(false);

    wall->setPhysicsBody(pWall);
    wall->setPosition(150, 0);
    wall->setColor(Color3B(255,255,255));
    wall->setRotation(10.0f);

    addChild(wall);

    /* �{�[�� */
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