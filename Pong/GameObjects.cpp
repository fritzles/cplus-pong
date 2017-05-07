/*
CS 120 Final Project
Pong: Game Object Implementations
Jordan Guzak, Michael Fritz, Chris Bracky
*/


#include "GameObjects.hpp"

using namespace std;

// ***************************
//  Global helper functions
double cint(double x) {
    if (modf(x, 0) >= .5)
        return x >= 0 ? ceil(x) : floor(x);
    else
        return x<0 ? ceil(x) : floor(x);
}

double round(double r, unsigned places) {
    double off = pow(10, places);
    return cint(r*off) / off;
}

// ***************************
//  Agent

Agent::Agent() {
    xPos = 0;
    yPos = 0;
    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}

Agent::~Agent() { }

void Agent::setcolor(color c) {
    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

void Agent::setX(double x) {
    xPos = x;
}

void Agent::setY(double y) {
    yPos = y;
}

color Agent::getcolor() const {
    return objColor;
}

double Agent::getX() const {
    return xPos;
}

double Agent::getY() const {
    return yPos;
}

Ball::Ball() {
    speed = 1;
    angle = 0;
    diameter = 1;

    setPos(0, 0);

    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}


Ball::Ball(double d) {
    speed = 1;
    angle = 0;
    diameter = d;

    setPos(0, 0);

    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}

Ball::Ball(double d, color c) {
    speed = 1;
    angle = 0;
    diameter = d;

    setPos(0, 0);

    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Ball::~Ball() { }

/** setters and getters */
void Ball::setAngle(int a) {
    angle = a%360;
}

void Ball::setSpeed(double s) {
    if (s >= 0) {
        speed = s;
    }
}

void Ball::setPos(int x, int y) {
    this->setX(x);
    this->setY(y);
}

int Ball::getAngle() const {
    return angle;
}

double Ball::getSpeed() const { return speed; }

/** override move function */
void Ball::move() {
    double xUpdate = round(cos(angle * M_PI / 180)) * speed;
    double yUpdate = round(sin(angle * M_PI / 180)) * speed;

    // rounding to compensate for math rounding errors
    xPos += xUpdate;
    yPos += yUpdate;

}

void Ball::draw() const {
    glBegin(GL_TRIANGLE_FAN);
    // center vertex is fill color
    glColor3ub(objColor.r, objColor.g, objColor.b);
    glVertex2i(getX(), getY());
    // edge vertices are outside color
    for (int i = 0; i <= 360; ++i) {
        double radians = i * M_PI / 180.0;
        glVertex2i(getX() + diameter/2 * cos(radians),
                   getY() + diameter/2 * sin(radians));
    }
    glEnd();
}

void Ball::isOverlapping(Paddle &p) {
//    cout << (xPos + (diameter/2))  << ":" << (p.getX() + p.getWidth()/2) << endl;
    if((floor(xPos + diameter/2) == p.getX()) || (floor(xPos - diameter/2) == (p.getX() + p.getWidth()))) {
        if(((yPos + diameter/2) >= p.getY()) &&
           ((yPos - diameter/2) <= (p.getY() + p.getLength()))) {
            //objColor = {25, 25, 112};
            setAngle(angle + 180 + 45 + p.getSpeed());
            setSpeed(speed + .01);
        } else {
            objColor = {173, 255, 0};
        }
    }
}

// ***************************
//  Paddle
Paddle::Paddle() {
    points = 0;
    length = 20;
    width = 2;
    speed = 1;
    direction = Up;
    xPos = 0;
    yPos = 0;

    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}

Paddle::Paddle(int l, double x, double y) {
    points = 0;
    length = l;
    width = 2;
    speed = 1;
    direction = Up;
    xPos = x;
    yPos = y;

    objColor.r = 255;
    objColor.g = 255;
    objColor.b = 255;
}

Paddle::Paddle(int l, double x, double y, color c) {
    points = 0;
    length = l;
    width = 2;
    speed = 1;
    direction = Up;
    xPos = x;
    yPos = y;

    objColor.r = c.r;
    objColor.g = c.g;
    objColor.b = c.b;
}

Paddle::~Paddle() { }

/** setters and getters */
void Paddle::setPaddleLocation(int x, int y) {
    xPos = x;
    yPos = y;
}

void Paddle::setDirection(PaddleDirection d) {
    direction = d;
}

void Paddle::setSpeed(double s) {
    if (s > 0) {
        speed = s;
    }
}

void Paddle::setLength(int l) {
    if (l > 0) {
        length = l;
    }
}

void Paddle::setWidth(int w) {
    if (w > 0) {
        width = w;
    }
}

int Paddle::getPoints() const {
    return points;
}

int Paddle::getLength() const {
    return length;
}

int Paddle::getWidth() const {
    return width;
}

double Paddle::getSpeed() const {
    return speed;
}

/** override move function */
void Paddle::move() {
    if (direction == Up) {
        yPos -= 1 * speed;
    }
    else {
        yPos += 1 * speed;
    }
}

void Paddle::draw() const {
    glBegin(GL_QUADS);
    glColor3ub(objColor.r, objColor.g, objColor.b);
    glVertex2i(getX(), getY());
    glVertex2i(getX(), getY() + length);
    glVertex2i(getX() + width, getY() + length);
    glVertex2i(getX() + width, getY());
    glEnd();

}

void Paddle::point() {
    points++;
}

// ***************************
//  Field
Field::Field() {
    width = DEFAULT_FIELD_WIDTH;
    height = DEFAULT_FIELD_HEIGHT;
    nextPaddle = 0;
    //fieldColor = BLACK;
}

Field::Field(int w, int h) {
    if (w > 0 && h > 0) {
        width = w;
        height = h;
    }
    else {
        width = DEFAULT_FIELD_WIDTH;
        height = DEFAULT_FIELD_HEIGHT;
    }

    fieldColor.r = 0;
    fieldColor.g = 0;
    fieldColor.b = 0;
    nextPaddle = 0;
}

Field::Field(int w, int h, color c) {
    if (w > 0 && h > 0) {
        width = w;
        height = h;
    }
    else {
        width = DEFAULT_FIELD_WIDTH;
        height = DEFAULT_FIELD_HEIGHT;
    }

    fieldColor.r = c.r;
    fieldColor.g = c.g;
    fieldColor.b = c.b;
    nextPaddle = 0;
}

Field::~Field() { }

/** setters and getters */
void Field::initalizePaddles() {
    leftPaddle.setPaddleLocation(0, height / 2);
    leftPaddle.setSpeed(10);
    leftPaddle.setWidth(5);
    leftPaddle.setLength(20);

    rightPaddle.setPaddleLocation(width - rightPaddle.getWidth(), height / 2);
    rightPaddle.setSpeed(10);
    rightPaddle.setWidth(5);
    rightPaddle.setLength(20);
}

void Field::initalizePaddles(Paddle l, Paddle r) {
    // store and place paddles
    leftPaddle = l;
    leftPaddle.setPaddleLocation(0, height/2);
    leftPaddle.setSpeed(10);
    leftPaddle.setWidth(5);
    leftPaddle.setLength(20);

    rightPaddle = r;
    rightPaddle.setPaddleLocation(width - rightPaddle.getWidth(), height / 2);
    rightPaddle.setSpeed(10);
    rightPaddle.setWidth(5);
    rightPaddle.setLength(20);
}

void Field::initalizeBall() {
    ball.setSpeed(.8);
    ball.diameter = 10;

    // first hit is to player 2, loser of the previous rally gets first hit
    if (nextPaddle == 0) {
        ball.setAngle(180);
    }
    else {
        ball.setAngle(0);
    }



    ball.setPos(width/2, height/2 + ball.diameter/2);
    ball.setcolor(fieldColor);
}

void Field::initalizeBall(Ball b) {
    ball = b;
    ball.setSpeed(.8);
    ball.diameter = 10;
    ball.setAngle(180 * rand() % 2);
    ball.setPos(width / 2, height / 2 + ball.diameter / 2);
    ball.setcolor(fieldColor);
}

void Field::setColor(color c) {
    fieldColor.r = c.r;
    fieldColor.g = c.g;
    fieldColor.b = c.b;
}

int Field::getHeight() const {
    return height;
}

int Field::getWidth() const {
    return width;
}

color Field::getColor() const {
    return fieldColor;
}

void Field::checkCollision() {
    ball.isOverlapping(rightPaddle);
    ball.isOverlapping(leftPaddle);

//    cout << (ball.getY() < 0) << endl;
    if(ball.getY() + ball.diameter > height) {
        ball.setAngle(ball.getAngle() + (360-90));
    } else if (ball.getY() - ball.diameter < 0) {
//        ball.setSpeed(0);
        ball.setAngle(ball.getAngle() + 45);
        cout << ball.getAngle() << endl;
    }

    // check for score
    if(ball.getX() > 600) {
        leftPaddle.point();
        nextPaddle = 1;
        initalizePaddles();
        initalizeBall();
    }else if( ball.getX() < 0){
        rightPaddle.point();
        nextPaddle = 0;
        initalizePaddles();
        initalizeBall();
    }
}

void Field::draw() const {
    
    // draw border color box
    glBegin(GL_QUADS);
    glColor3ub(fieldColor.r, fieldColor.g, fieldColor.b);
    glVertex2i(0, -10);
    glVertex2i(0, height+10);
    glVertex2i(width, height+10);
    glVertex2i(width, -10);
    glEnd();

    // draw blank field
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2i(0, 0);
    glVertex2i(0, height);
    glVertex2i(width, height);
    glVertex2i(width, 0);
    glEnd();

}
