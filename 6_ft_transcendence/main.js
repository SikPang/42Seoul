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
,	b2DebugDraw = Box2D.Dynamics.b2DebugDraw;

var gameObjects = {};
var y = 3.5;

function drawObject(gameObjects, tag, fixDef, isStatic, isSquare, x, y, width, height, linearVelocityX, linearVelocityY, angularVelocity) {
	var bodyDef = new b2BodyDef;

	if (isStatic)
		bodyDef.type = b2Body.b2_staticBody;
	else
		bodyDef.type = b2Body.b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.linearVelocity = new b2Vec2(linearVelocityX, linearVelocityY);
	if (angularVelocity)
		bodyDef.angularVelocity = angularVelocity;
	if (isSquare)
	{
		fixDef.shape = new b2PolygonShape;
		fixDef.shape.SetAsBox(width, height);
		bodyDef.linearDamping = 1.0;
	}
	else
	{
		fixDef.shape = new b2CircleShape(width);
	}
	let body = world.CreateBody(bodyDef);
	body.CreateFixture(fixDef);
	gameObjects[tag] = body;
}

function keyDownEvent(event)
{
	if (event.keyCode == 38) // Arrow Up
	{
		gameObjects["leftRacket"].SetLinearVelocity(new b2Vec2(0, -10));
		gameObjects["rightRacket"].SetLinearVelocity(new b2Vec2(0, -10));
	}
	else if (event.keyCode == 40) // Arrow Down
	{
		gameObjects["leftRacket"].SetLinearVelocity(new b2Vec2(0, +10));
		gameObjects["rightRacket"].SetLinearVelocity(new b2Vec2(0, +10));
	}
	else
		return;
}


function keyUpEvent(event) {
	if (event.keyCode == 38) // Arrow Up
	{
		gameObjects["leftRacket"].SetLinearVelocity(new b2Vec2(0, 0));
		gameObjects["rightRacket"].SetLinearVelocity(new b2Vec2(0, 0));
	}
	else if (event.keyCode == 40) // Arrow Down
	{
		gameObjects["leftRacket"].SetLinearVelocity(new b2Vec2(0, 0));
		gameObjects["rightRacket"].SetLinearVelocity(new b2Vec2(0, 0));
	}
	else
		return;
}

function init() {
	document.addEventListener("keydown", keyDownEvent);
	document.addEventListener('keyup', keyUpEvent);

	world = new b2World(
			new b2Vec2(0, 0)    //gravity
			, true              //allow sleep
	);

	var fixDef = new b2FixtureDef;
	fixDef.density = 1.0;
	fixDef.friction = 0.0;
	fixDef.restitution = 1.0;

	// create walls
	drawObject(gameObjects, "leftWall", fixDef, true, true, 0, 4, 0.1, 5, 0, 0, 0);
	drawObject(gameObjects, "rightWall", fixDef, true, true, 12.8, 4, 0.1, 5, 0, 0, 0);
	drawObject(gameObjects, "upWall", fixDef, true, true, 6, 0, 7, 0.1, 0, 0, 0);
	drawObject(gameObjects, "downWall", fixDef, true, true, 6, 7.2, 7, 0.1, 0, 0, 0);
		
	// create a ball
	var randValHorizon = Math.ceil(Math.random() * 100) % 2 ? 1 : -1;
	var randValVertical = Math.ceil(Math.random() * 100) % 2 ? 1 : -1;
	var randValSpin = Math.ceil(Math.random() * 100) % 2 ? 1 : -1;
	drawObject(gameObjects, "ball", fixDef, false, false, 6, 4, 0.1, 0, 5 * randValHorizon, 5 * randValVertical, 20 * randValSpin);
	
	fixDef.density = 100;
	fixDef.friction = 0.01;
	fixDef.restitution = 0;
	// create rackets
	drawObject(gameObjects, "leftRacket", fixDef, false, true, 0.3, y, 0.1, 0.5, 0, 0, 0);
	drawObject(gameObjects, "rightRacket", fixDef, false, true, 0.7 + 11.8, y, 0.1, 0.5, 0, 0, 0);

	gameObjects["ball"].isBullet = true;
	gameObjects["leftRacket"].isBullet = true;
	gameObjects["rightRacket"].isBullet = true;
   
   //setup debug draw
   var debugDraw = new b2DebugDraw();		
   debugDraw.SetSprite(document.getElementById("canvas").getContext("2d"));		
   debugDraw.SetDrawScale(100.0);		
   debugDraw.SetFillAlpha(0.3);		
   debugDraw.SetLineThickness(1.1);		
   debugDraw.SetFlags(b2DebugDraw.e_shapeBit | b2DebugDraw.e_jointBit);		
   world.SetDebugDraw(debugDraw);
   
   window.setInterval(update, 1000 / 60);
};

function update() {
	let fps = 60;
	world.Step(
	      1 / fps   //frame-rate
	   ,  10       //velocity iterations
	   ,  10       //position iterations
	);
	gameObjects["leftRacket"].SetAngle(0);
	gameObjects["rightRacket"].SetAngle(0);
	gameObjects["leftRacket"].SetAwake(true);
	gameObjects["rightRacket"].SetAwake(true);
	world.DrawDebugData();
	world.ClearForces();
};