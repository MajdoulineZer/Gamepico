#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    layer->SetPhysicsWorld(scene->getPhysicsWorld());

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    ///////////////////////////////////////////////////////////////
    auto background = Sprite::create("white.png");
    float x = origin.x + visibleSize.width / 2;
    float y = origin.y + visibleSize.height / 2;
    background->setPosition(Vec2(x, y));
    this->addChild(background);
    //////////////////////////////////////////////////////////
     auto floor = Sprite::create("Floor.png");

    // set the initial position of the floor
    floor->setPosition(Vec2(0, 0));

    // add the floor to the scene
    this->addChild(floor);

    // update the position of the floor as the player moves
    floor->setPosition(floor->getPosition() + Vec2(1, 0));


    ////////////////////////////////
    auto titre = Sprite::create("title.png");
    titre->setPosition(Vec2(470, 480));
    this->addChild(titre);


    ///////////////////////////////////////////////////////
    ///La premi�re ligne de code cr�e un corps physique sous la forme d'une bo�te en utilisant la m�thode createEdgeBox de la classe PhysicsBody. La m�thode createEdgeBox prend deux arguments : la taille de la bo�te et une constante de mat�riau (PHYSICSBODY_MATERIAL_DEFAULT) qui sp�cifie les propri�t�s physiques du corps. La taille de la bo�te est sp�cifi�e en utilisant un objet Size, qui dans ce cas est visibleSize, une variable qui repr�sente la taille visible de l'�cran. Le troisi�me argument, 3, sp�cifie l'�paisseur des bords de la bo�te.

   /// La seconde ligne de code cr�e un nouveau n�ud en utilisant la m�thode Node::create.Ce n�ud sera utilis� pour attacher le corps physique.

   //  La troisi�me ligne de code d�finit la position du n�ud au centre de l'�cran. La position est sp�cifi�e en utilisant un objet Point, qui est cr�� en utilisant les variables visibleSize et origin. La variable origin repr�sente le coin inf�rieur gauche de l'�cran, et la variable visibleSize repr�sente la taille de la zone visible de l'�cran.

   /// La quatri�me ligne de code d�finit le corps physique cr�� dans la premi�re ligne de code comme le corps physique du n�ud en utilisant la m�thode setPhysicsBody.

     /// Enfin, la cinqui�me ligne de code ajoute le n�ud avec le corps physique attach� en tant qu'enfant de l'objet actuel(presum�ment un certain type d'objet conteneur dans le jeu ou la simulation). Cela fera en sorte que le corps physique soit affich� � l'�cran et interagisse avec d'autres corps physiques dans la simulation selon les lois de la physique.///////


    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);





    return true;
}