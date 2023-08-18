var world;
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

console.log(tempString);

function drawObject(isStatic, isSquare, x, y, width, height, linearVelocityX, linearVelocityY, angularVelocity) {
	var fixDef = new b2FixtureDef;
	fixDef.density = 0.0;
	fixDef.friction = 0.0;
	fixDef.restitution = 1.0;

	var bodyDef = new b2BodyDef;

	if (isStatic)
		bodyDef.type = b2Body.b2_staticBody;
	else
		bodyDef.type = b2Body.b2_dynamicBody;
	bodyDef.position.x = x;
	bodyDef.position.y = y;
	if (linearVelocityX && linearVelocityY)
		bodyDef.linearVelocity = new b2Vec2(linearVelocityX, linearVelocityY);
	if (angularVelocity)
		bodyDef.angularVelocity = angularVelocity;
	if (isSquare)
	{
		fixDef.shape = new b2PolygonShape;
		fixDef.shape.SetAsBox(width, height);
	}
	else
		fixDef.shape = new b2CircleShape(width);
	world.CreateBody(bodyDef).CreateFixture(fixDef);
}
      
function init() {
   world = new b2World(
         new b2Vec2(0, 0)    //gravity
      ,  true                //allow sleep
   );

	// create walls
	for (var i = 0; i < 2; ++i)
		drawObject(true, true, i * 12.8, 4, 0.1, 5, 0, 0, 0);
	for (var i = 0; i < 2; ++i)
		drawObject(true, true, 6, i * 7.2, 7, 0.1, 0, 0, 0);

	// create rackets
	for (var i = 0; i < 2; ++i)
		drawObject(true, true, 0.5 + i * 11.8, 4, 0.1, 0.5, 0, 0, 0);

	// create a ball
	drawObject(false, false, 6, 4, 0.1, 0, 5, 5, 10.0);
   
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