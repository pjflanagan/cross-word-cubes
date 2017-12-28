#include "Cube.h"

static const int Cube::SIDES = 6;

static const Letter Cube::A = Letter('a', 1);
static const Letter Cube::B = Letter('b', 1);
static const Letter Cube::C = Letter('c', 1);
static const Letter Cube::D = Letter('d', 1);
static const Letter Cube::E = Letter('e', 1);
static const Letter Cube::F = Letter('f', 1);
static const Letter Cube::G = Letter('g', 1);
static const Letter Cube::H = Letter('h', 1);
static const Letter Cube::I = Letter('i', 1);
static const Letter Cube::J = Letter('j', 1);
static const Letter Cube::K = Letter('k', 1);
static const Letter Cube::L = Letter('l', 1);
static const Letter Cube::M = Letter('m', 1);
static const Letter Cube::N = Letter('n', 1);
static const Letter Cube::O = Letter('o', 1);
static const Letter Cube::P = Letter('p', 1);
static const Letter Cube::Q = Letter('q', 1);
static const Letter Cube::R = Letter('r', 1);
static const Letter Cube::S = Letter('s', 1);
static const Letter Cube::T = Letter('t', 1);
static const Letter Cube::U = Letter('u', 1);
static const Letter Cube::V = Letter('v', 1);
static const Letter Cube::W = Letter('w', 1);
static const Letter Cube::X = Letter('x', 1);
static const Letter Cube::Y = Letter('y', 1);
static const Letter Cube::Z = Letter('z', 1);

static refrence['a'] = A;
static refrence['b'] = B;
static refrence['c'] = C;
static refrence['d'] = D;
static refrence['e'] = E;
static refrence['f'] = F;
static refrence['g'] = G;
static refrence['h'] = H;
static refrence['i'] = I;
static refrence['j'] = J;
static refrence['k'] = K;
static refrence['l'] = L;
static refrence['m'] = M;
static refrence['n'] = N;
static refrence['o'] = O;
static refrence['p'] = P;
static refrence['q'] = Q;
static refrence['r'] = R;
static refrence['s'] = S;
static refrence['t'] = T;
static refrence['u'] = U;
static refrence['v'] = V;
static refrence['w'] = W;
static refrence['x'] = X;
static refrence['y'] = Y;
static refrence['z'] = Z;

Cube::Cube(const std::string &faces_in){
	for(int i = 0; i < SIDES; ++i){
		faces[i] = refrence[faces_in[i]];
	}
}

// RETURNS a Letter representing the up face
Letter Cube::get_up() const {
	return faces[up];
}

// RETURNS the char representing the up face
char Cube::get_up_char() const {
	get_up().character;
}

// RETURNS the value of the up face
int Cube::get_up_val() const {
	get_up().value;
}