var gl;

function initWebGL(canvas)
{
	try 
	{
		gl = canvas.getContext("webgl")
			|| canvas.getContext("experimental-webgl");
		return gl;
	}
	catch (e)
	{
		return null;
	}
}

function start()
{
	var canvas = document.getElementById("canvas");
	gl = initWebGL(canvas);  
	if (!gl)
	{
		alert("Unable to initialize WebGL. Your browser may not support it.");
		return;
	}
	gl.viewport(0, 0, canvas.width, canvas.height);
	gl.clearColor(0.0, 0.0, 0.0, 1.0);
	gl.enable(gl.DEPTH_TEST);
	gl.depthFunc(gl.LEQUAL);
	gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
}