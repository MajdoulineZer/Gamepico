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
    ///La première ligne de code crée un corps physique sous la forme d'une boîte en utilisant la méthode createEdgeBox de la classe PhysicsBody. La méthode createEdgeBox prend deux arguments : la taille de la boîte et une constante de matériau (PHYSICSBODY_MATERIAL_DEFAULT) qui spécifie les propriétés physiques du corps. La taille de la boîte est spécifiée en utilisant un objet Size, qui dans ce cas est visibleSize, une variable qui représente la taille visible de l'écran. Le troisième argument, 3, spécifie l'épaisseur des bords de la boîte.

   /// La seconde ligne de code crée un nouveau nœud en utilisant la méthode Node::create.Ce nœud sera utilisé pour attacher le corps physique.

   //  La troisième ligne de code définit la position du nœud au centre de l'écran. La position est spécifiée en utilisant un objet Point, qui est créé en utilisant les variables visibleSize et origin. La variable origin représente le coin inférieur gauche de l'écran, et la variable visibleSize représente la taille de la zone visible de l'écran.

   /// La quatrième ligne de code définit le corps physique créé dans la première ligne de code comme le corps physique du nœud en utilisant la méthode setPhysicsBody.

     /// Enfin, la cinquième ligne de code ajoute le nœud avec le corps physique attaché en tant qu'enfant de l'objet actuel(presumément un certain type d'objet conteneur dans le jeu ou la simulation). Cela fera en sorte que le corps physique soit affiché à l'écran et interagisse avec d'autres corps physiques dans la simulation selon les lois de la physique.///////


    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    edgeNode->setPhysicsBody(edgeBody);

    this->addChild(edgeNode);





    return true;
}