#include "catplayer.h"
#include "Definition.h"

USING_NS_CC;


CAT::CAT(cocos2d::Layer* layer)
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

    mySprite = Sprite::create("0_stand1.png");

    mySprite->setPosition(Vec2(90, 100));
    layer->addChild(mySprite);

   
}
