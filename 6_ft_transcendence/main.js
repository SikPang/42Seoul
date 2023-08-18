var world;

console.log(tempString);
      
function init() {
   var   b2Vec2 = Box2D.Common.Math.b2Vec2
   	,	b2BodyDef = Box2D.Dynamics.b2BodyDef
   	,	b2Body = Box2D.Dynamics.b2Body
   	,	b2FixtureDef = Box2D.Dynamics.b2FixtureDef
   	,	b2Fixture = Box2D.Dynamics.b2Fixture
   	,	b2World = Box2D.Dynamics.b2World
   	,	b2MassData = Box2D.Collision.Shapes.b2MassData
   	,	b2PolygonShape = Box2D.Collision.Shapes.b2PolygonShape
   	,	b2CircleShape = Box2D.Collision.Shapes.b2CircleShape
   	,	b2DebugDraw = Box2D.Dynamics.b2DebugDraw
      ;
   
   world = new b2World(
         new b2Vec2(0, 0)    //gravity
      ,  true                //allow sleep
   );
   
   var fixDef = new b2FixtureDef;
   fixDef.density = 0.0;
   fixDef.friction = 0.1;
   fixDef.restitution = 1.0;
   
   var bodyDef = new b2BodyDef;

	//create wall vertical
	for (var i = 0; i < 2; ++i) {
		bodyDef.type = b2Body.b2_staticBody;
		bodyDef.position.x = i * 12.8;
		bodyDef.position.y = 4;
		fixDef.shape = new b2PolygonShape;
		fixDef.shape.SetAsBox(0.1, 5);
		world.CreateBody(bodyDef).CreateFixture(fixDef);
	}

	//create wall horizontal
	for (var i = 0; i < 2; ++i) {
		bodyDef.type = b2Body.b2_staticBody;
		bodyDef.position.x = 6;
		bodyDef.position.y = i * 7.2;
		fixDef.shape = new b2PolygonShape;
		fixDef.shape.SetAsBox(7, 0.1);
		world.CreateBody(bodyDef).CreateFixture(fixDef);
	}

	//create racket
	for (var i = 0; i < 2; ++i) {
		bodyDef.type = b2Body.b2_staticBody;
		bodyDef.position.x = 0.5 + i * 11.8;
		bodyDef.position.y = 4;
		fixDef.shape = new b2PolygonShape;
		fixDef.shape.SetAsBox(0.1, 0.5);
		world.CreateBody(bodyDef).CreateFixture(fixDef);
	}

	//create ball
	bodyDef.type = b2Body.b2_dynamicBody;
	fixDef.shape = new b2CircleShape(0.1);
	bodyDef.position.x = 6;
	bodyDef.position.y = 4;
	bodyDef.linearVelocity = new b2Vec2(5, 0);
	bodyDef.angularVelocity = 10.0;
	world.CreateBody(bodyDef).CreateFixture(fixDef);
   
   //setup debug draw
   var debugDraw = new b2DebugDraw();		
   debugDraw.SetSprite(document.getElementById("canvas").getContext("2d"));		
   debugDraw.SetDrawScale(100.0);		
   debugDraw.SetFillAlpha(0.3);		
   debugDraw.SetLineThickness(1.1);		
   debugDraw.SetFlags(b2DebugDraw.e_shapeBit | b2DebugDraw.e_jointBit);		
   world.SetDebugDraw(debugDraw);

   //var myInt: number = 1;
   
   window.setInterval(update, 1000 / 60);
};

function update() {
	let fps = 60;
	world.Step(
	      1 / fps   //frame-rate
	   ,  10       //velocity iterations
	   ,  10       //position iterations
	);
	world.DrawDebugData();
	world.ClearForces();
};