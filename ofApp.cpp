#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofNoFill();
	ofSetLineWidth(1.2);
	
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;
	for (int k = 0; k < 150; k++) {

		color.setHsb(ofRandom(255), 180, 230);

		ofPushMatrix();
		ofRotateY(ofRandom(360));

		auto location = glm::vec3(0, 0, 250);
		auto radius = (int)(ofRandom(1000) + ofGetFrameNum() * 4) % 150 - 100;

		if (radius < 0) {

			auto z = ofMap(radius, -100, 0, 1500, 0);

			ofSetColor(color);
			ofDrawLine(location + glm::vec3(0, 0, z), location + glm::vec3(0, 0, z + 40));
		}
		else {

			ofSetColor(color, radius > 25 ? ofMap(radius, 25, 50, 255, 0) : 255);
			
			ofBeginShape();
			for (int deg = 0; deg < 360; deg++) {

				auto vertex = location + glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				vertex = glm::normalize(vertex) * 250;

				ofVertex(vertex);
			}
			ofEndShape(true);
		}

		ofPopMatrix();
	}

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}