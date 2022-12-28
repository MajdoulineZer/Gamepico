#ifndef __CATPLAYER_H__
#define __CATPLAYER_H__

#include "cocos2d.h"

class CAT
{
public:
    CAT(cocos2d::Layer* layer);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

    cocos2d::Sprite* mySprite;
   

};

#endif // __CATPLAYER_H__