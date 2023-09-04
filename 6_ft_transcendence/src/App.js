import React, { Fragment, useState, useCallback, useEffect } from "react";
import { Unity, useUnityContext } from "react-unity-webgl";

function App() {
  const { unityProvider, sendMessage, addEventListener, removeEventListener } = useUnityContext({
    loaderUrl: "build/1.loader.js",
    dataUrl: "build/1.data.unityweb",
    frameworkUrl: "build/1.framework.js.unityweb",
    codeUrl: "build/1.wasm.unityweb",
  });

  // react to unity
  function ButtonEvent()
  {
	sendMessage("GameManager", "StartGame");
  }

  // unity to react
  const [gameOver, setGameOver] = useState();
  const handleGameOver = useCallback(() => {
    setGameOver(true);
  }, []);

  useEffect(() => {
    addEventListener("GameOver", handleGameOver);
    return () => {
      removeEventListener("GameOver", handleGameOver);
    };
  }, [addEventListener, removeEventListener, handleGameOver]);

  return (
	<Fragment>
	<div className="App">
		{gameOver === true && (
			<p>{`Game Over!`}</p>
		)}
		<button onClick={ButtonEvent}> 시작 버튼 </button>
		<Unity unityProvider={unityProvider} style={{ width: 800, height: 600 }} />
	</div>
	</Fragment>
  );
}

export default App;
