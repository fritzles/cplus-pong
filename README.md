# beer-pong
CS120 Final Project

<<<<<<< HEAD
Jordan Guzak
Michael Fritz
Chris Bratkovics

Core classes:
	Agent
		// setters
		setcolor
		setX
		setY

		// getters
		getcolor
		getX
		getY

		virtual move

		xPos
		yPos
		color

	Ball : public Agent
		// setters
		setAngle
		setSpeed
		setPos

		// getters
		getAngle
		getSpeed

		move override

		angle
		speed

	Paddle : public Agent
		// setters
		setPaddleLocation
		setDirection
		setSpeed

		// getters
		getPoints
		getLength
		getWidth
		getSpeed

		move override

		points
		length
		width
		direction
		speed

	Field
		initalizePaddles
		initalizeBall

		// getters
		getHeight
		getWidth
		getColor

		height
		width
		color
		leftPaddle
		rightPaddle
		Ball

	Player
		saveData
		loadData

		getName
		getGamesPlayed
		getGamesWon
		getGamesLost

		setName
		setGamesPlayed
		setGamesWon

		gamesPlayed
		gamesWon
		name

	Gameplay
		// setters
		setField
		setField

		void checkContact();

		ballFieldYTouch
		ballFieldTouchLeft
		ballFieldTouchRight
		paddleFieldTouchTop
		paddleFieldTouchBottom
		paddleBallTouch

		gameOver
		gameStart
		score

		field
		player1
		player2
		player1Score
		player2Score

		
Stretch goals:
	Changeable colors for players, ball, field
	Alternative physics
	Games based on timer, with support for keeping track of lifetime points scored
	Four player mode
	Custom ball textures

=======

Sick Dank Nasty
>>>>>>> origin/master
