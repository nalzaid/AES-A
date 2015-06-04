#include <stdio.h>
#include <conio.h>
#include <windows.h>


typedef unsigned char		BYTE;
BYTE S_BOX[256] =
{
	0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
	0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0,
	0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15,
	0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75,
	0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84,
	0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF,
	0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8,
	0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2,
	0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73,
	0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB,
	0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79,
	0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08,
	0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A,
	0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E,
	0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF,
	0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16
};


BYTE INV_S_BOX[256] =
{
	0x52, 0x09, 0x6A, 0xD5, 0x30, 0x36, 0xA5, 0x38, 0xBF, 0x40, 0xA3, 0x9E, 0x81, 0xF3, 0xD7, 0xFB,
	0x7C, 0xE3, 0x39, 0x82, 0x9B, 0x2F, 0xFF, 0x87, 0x34, 0x8E, 0x43, 0x44, 0xC4, 0xDE, 0xE9, 0xCB,
	0x54, 0x7B, 0x94, 0x32, 0xA6, 0xC2, 0x23, 0x3D, 0xEE, 0x4C, 0x95, 0x0B, 0x42, 0xFA, 0xC3, 0x4E,
	0x08, 0x2E, 0xA1, 0x66, 0x28, 0xD9, 0x24, 0xB2, 0x76, 0x5B, 0xA2, 0x49, 0x6D, 0x8B, 0xD1, 0x25,
	0x72, 0xF8, 0xF6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xD4, 0xA4, 0x5C, 0xCC, 0x5D, 0x65, 0xB6, 0x92,
	0x6C, 0x70, 0x48, 0x50, 0xFD, 0xED, 0xB9, 0xDA, 0x5E, 0x15, 0x46, 0x57, 0xA7, 0x8D, 0x9D, 0x84,
	0x90, 0xD8, 0xAB, 0x00, 0x8C, 0xBC, 0xD3, 0x0A, 0xF7, 0xE4, 0x58, 0x05, 0xB8, 0xB3, 0x45, 0x06,
	0xD0, 0x2C, 0x1E, 0x8F, 0xCA, 0x3F, 0x0F, 0x02, 0xC1, 0xAF, 0xBD, 0x03, 0x01, 0x13, 0x8A, 0x6B,
	0x3A, 0x91, 0x11, 0x41, 0x4F, 0x67, 0xDC, 0xEA, 0x97, 0xF2, 0xCF, 0xCE, 0xF0, 0xB4, 0xE6, 0x73,
	0x96, 0xAC, 0x74, 0x22, 0xE7, 0xAD, 0x35, 0x85, 0xE2, 0xF9, 0x37, 0xE8, 0x1C, 0x75, 0xDF, 0x6E,
	0x47, 0xF1, 0x1A, 0x71, 0x1D, 0x29, 0xC5, 0x89, 0x6F, 0xB7, 0x62, 0x0E, 0xAA, 0x18, 0xBE, 0x1B,
	0xFC, 0x56, 0x3E, 0x4B, 0xC6, 0xD2, 0x79, 0x20, 0x9A, 0xDB, 0xC0, 0xFE, 0x78, 0xCD, 0x5A, 0xF4,
	0x1F, 0xDD, 0xA8, 0x33, 0x88, 0x07, 0xC7, 0x31, 0xB1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xEC, 0x5F,
	0x60, 0x51, 0x7F, 0xA9, 0x19, 0xB5, 0x4A, 0x0D, 0x2D, 0xE5, 0x7A, 0x9F, 0x93, 0xC9, 0x9C, 0xEF,
	0xA0, 0xE0, 0x3B, 0x4D, 0xAE, 0x2A, 0xF5, 0xB0, 0xC8, 0xEB, 0xBB, 0x3C, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2B, 0x04, 0x7E, 0xBA, 0x77, 0xD6, 0x26, 0xE1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0C, 0x7D
};



unsigned char GF256multiplication(unsigned char b, unsigned char a) {
	int i = 0;
	unsigned char result = 0;
	unsigned char BYTE_LEFT_BIT = 0x80;
	unsigned char BYTE_Right_BIT = 0x01;

	for (i = 0; i < 8; i++)	{
		if (a & BYTE_Right_BIT)
			result ^= b;

		if ((b & BYTE_LEFT_BIT) == BYTE_LEFT_BIT){
			b <<= 1;
			b ^= 0x1b;// b mod x^4+x^3+x+1 
		}
		else{
			b <<= 1;
		}
		a >>= 1;
	}
	return result;
}




/*void SR(unsigned char s[4][4] , int f)
{
	int temp;

	if (f == 0)// SR for ENC
	{
		//row1 
		temp = s[1][0];
		s[1][0] = s[1][1];
		s[1][1] = s[1][2];
		s[1][2] = s[1][3];
		s[1][3] = temp;

		//row2
		temp = s[2][0];
		s[2][0] = s[2][2];
		s[2][2] = temp;
		temp = s[2][1];
		s[2][1] = s[2][3];
		s[2][3] = temp;

		//row 3 
		temp = s[3][0];
		s[3][0] = s[3][3];
		s[3][3] = s[3][2];
		s[3][2] = s[3][1];
		s[3][1] = temp;
	}

	else if (f == 1)//SR for DEC
	{
		//row1 
		temp = s[1][0];
		s[1][0] = s[1][3];
		s[1][3] = s[1][2];
		s[1][2] = s[1][1];
		s[1][1] = temp;

	

		//row2
		temp = s[2][0];
		s[2][0] = s[2][2];
		s[2][2] = temp;
		
		temp = s[2][3];
		s[2][3] = s[2][1];
		s[2][1] = temp;

		//row 3 
		temp = s[3][3];
		s[3][3] = s[3][0];
		s[3][0] = s[3][1];
		s[3][1] = s[3][2];
		s[3][2] = temp;
	}
}*/


void keyExp(unsigned char k[4][4], unsigned char res[4][44])
{

	int i, j,x;
	int r, count;
	unsigned char t;
	unsigned char temp[4];

	unsigned char rcon[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36 }; 
	count = 0;
	
//1st round key (col 0 - col 3)
	for (i = 3; i >= 0; i--)
		for (j = 3; j >= 0; j--)
			res[i][j] = k[i][j];

	// col 4 - col 43

	for (j = 4; j < 44; j=j+4)//each time this loop will fill 4 col at a time, so it will be done 11 times only
	{
			for (r = 0; r < 4; r++)
				temp[r] = res[r][j - 1];


			
			//rotate word

			t = temp[0];
			temp[0] = temp[1];
			temp[1] = temp[2];
			temp[2] = temp[3];
			temp[3] = t;

			
			


			//subbyte
			for (i = 0; i < 4; i++)
				temp[i] = S_BOX[temp[i]];

			

			//3XOR 
		
			
					res[0][j] = res[0][j - 4] ^ temp[0] ^ rcon[count];
					
					res[1][j] = res[1][j - 4] ^ temp[1];
					res[2][j] = res[2][j - 4] ^ temp[2];
					res[3][j] = res[3][j - 4] ^ temp[3];
					count++;

		// the rest col after j 
			for (x = 1; x <= 3; x++)
			{
				for (r = 0; r < 4; r++)
					res[r][j + x] = res[r][(j+x) - 1] ^ res[r][(j+x)- 4];
			}
			
	}// end for loop

}

void MC(unsigned char s[4][4], unsigned char res[4][4], int f)
{
	unsigned int   m[4][4] = { { 0x02, 0x03, 0x01, 0x01 },
	{ 0x01, 0x02, 0x03, 0x01 },
	{ 0x01, 0x01, 0x02, 0x03 },
	{ 0x03, 0x01, 0x01, 0x02 } };

	unsigned int   mDEC[4][4] = { { 0x0E, 0x0B, 0x0D, 0x09 },
	{ 0x09, 0x0E, 0x0B, 0x0D },
	{ 0x0D, 0x09, 0x0E, 0x0B },
	{ 0x0B, 0x0D, 0x09, 0x0E } };

	
	int c, r, k;

	for (r = 0; r < 4; r++)
		for (c = 0; c < 4; c++)
			res[r][c] = 0x00;
	
	if (f == 0)
	{
		for (c = 0; c < 4; c++)
			for (r = 0; r < 4; r++)
				for (k = 0; k < 4; k++)
					res[r][c] ^= GF256multiplication(s[k][c], m[r][k]);

	}

	else if (f == 1)
	{
		
		for (c = 0; c < 4; c++)
			for (r = 0; r < 4; r++)
				for (k = 0; k < 4; k++)
					res[r][c] ^= GF256multiplication(s[k][c], mDEC[r][k]);

	}

}

void AES_ENC(unsigned char state[4][4], unsigned char key[4][44], int col)
{
	int i, j,s,w ,r, f;// s,w,r 
	char tem;
	unsigned char temp[4][4];

	unsigned char res[4][4];

	//Add the first round key
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			state[i][j] ^= key[i][j];


	for (f = 0; f<9; f++)
	{
		//Sub-Bytes
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				state[i][j] = S_BOX[state[i][j]];

		//Shift Rows:
	
		//row1 
		tem = state[1][0];
		state[1][0] = state[1][1];
		state[1][1] = state[1][2];
		state[1][2] = state[1][3];
		state[1][3] = tem;

		//row2
		tem = state[2][0];
		state[2][0] = state[2][2];
		state[2][2] = tem;
		tem = state[2][1];
		state[2][1] = state[2][3];
		state[2][3] = tem;

		//row 3 
		tem = state[3][0];
		state[3][0] = state[3][3];
		state[3][3] = state[3][2];
		state[3][2] = state[3][1];
		state[3][1] = tem;

		//Mix-Columns
		MC(state, res, 0);

		for (s = 0; s < 4; s++)
			for (w = 0; w < 4; w++)
				state[s][w] = res[s][w];

		//get the round key:
		for (r = 0; r < 4; r++)
		{
			for (j = 0; j < 4; j++)
			{
				temp[r][j] = key[r][col];
				col++;

			}
			col = col - 4;
		}
		col = col + 4;
		
		//Add round key:
		for (i = 0; i<4; i++)
			for (j = 0; j<4; j++)
				state[i][j] ^= temp[i][j];

	}


	// -------------------------
	//----- Last Round ---------
	//--------------------------

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			state[i][j] = S_BOX[state[i][j]];


	//Shift Rows:
	 
	//row1 
	tem = state[1][0];
	state[1][0] = state[1][1];
	state[1][1] = state[1][2];
	state[1][2] = state[1][3];
	state[1][3] = tem;

	//row2
	tem = state[2][0];
	state[2][0] = state[2][2];
	state[2][2] = tem;
	tem = state[2][1];
	state[2][1] = state[2][3];
	state[2][3] = tem;

	//row 3 
	tem = state[3][0];
	state[3][0] = state[3][3];
	state[3][3] = state[3][2];
	state[3][2] = state[3][1];
	state[3][1] = tem;



	// get the last round key:
	for (r = 0; r < 4; r++)
	{
		for (j = 0; j < 4; j++)
		{
			temp[r][j] = key[r][col];
			col++;

		}
		col = col - 4;
	}


	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			state[i][j] ^= temp[i][j];

}

void AES_DEC(unsigned char state[4][4], unsigned char key[4][44], int col)
{
	int i, j,f;
	char tem;
	unsigned char temp[4][4];

	unsigned char res[4][4];

	//get the round key:
	for (i = 0; i < 4;i++)
	{
		for (j = 0; j < 4; j++)
		{
			temp[i][j] = key[i][col];
			col++;

		}
		col = col - 4;
	}
	col = col - 4;


	//Add round key first time with the chiper text
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			state[i][j] ^= temp[i][j];


	for (f = 9; f > 0; f--)
	{
		//InvSR
		//row1 
		tem = state[1][0];
		state[1][0] = state[1][3];
		state[1][3] = state[1][2];
		state[1][2] = state[1][1];
		state[1][1] = tem;



		//row2
		tem = state[2][0];
		state[2][0] = state[2][2];
		state[2][2] = tem;

		tem = state[2][3];
		state[2][3] = state[2][1];
		state[2][1] = tem;

		//row 3 
		tem = state[3][3];
		state[3][3] = state[3][0];
		state[3][0] = state[3][1];
		state[3][1] = state[3][2];
		state[3][2] = tem;


		//InvSB
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				state[i][j] = INV_S_BOX[state[i][j]];

		//get round key
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				temp[i][j] = key[i][col];
				col++;

			}
			col = col - 4;
		}
		col = col - 4;

		//ARK
		for (i = 0; i<4; i++)
			for (j = 0; j<4; j++)
				state[i][j] ^= temp[i][j];

		//MC
		MC(state, res, 1);


		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				state[i][j] = res[i][j];
	}

	// Last round

	//InvSR
	//row1 
	tem = state[1][0];
	state[1][0] = state[1][3];
	state[1][3] = state[1][2];
	state[1][2] = state[1][1];
	state[1][1] = tem;



	//row2
	tem = state[2][0];
	state[2][0] = state[2][2];
	state[2][2] = tem;

	tem = state[2][3];
	state[2][3] = state[2][1];
	state[2][1] = tem;

	//row 3 
	tem = state[3][3];
	state[3][3] = state[3][0];
	state[3][0] = state[3][1];
	state[3][1] = state[3][2];
	state[3][2] = tem;


	//InvSB
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			state[i][j] = INV_S_BOX[state[i][j]];

	//ARK
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			state[i][j] = state[i][j] ^ key[i][j];
}


void main()
{
	int i, j, t; 
	LARGE_INTEGER FREQUENCY;									// Ticks per Second
	LARGE_INTEGER START_TIME, END_TIME;						// Start and End Time Counter
	double ELAPSED_TIME;
	unsigned char state[4][4] = { { 0x32, 0x88, 0x31, 0xE0 },
	{ 0x43, 0x5A, 0x31, 0x37 },
	{ 0xF6, 0x30, 0x98, 0x07 },
	{ 0xA8, 0x8D, 0xA2, 0x34 } };

	unsigned char key[4][4] = { { 0x2B, 0x28, 0xAB, 0x09 },
	{ 0x7E, 0xAE, 0xF7, 0xCF },
	{ 0x15, 0xD2, 0x15, 0x4F },
	{ 0x16, 0xA6, 0x88, 0x3C } };

	unsigned char exKey[4][44];


	printf("The input state content: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", state[i][j]);

		printf("\n");
	}

	keyExp(key,exKey);

	//** Timing Measurment 1 / 2 **//
	QueryPerformanceFrequency(&FREQUENCY);
	QueryPerformanceCounter(&START_TIME);						// Start Timer
	for (t = 0; t < 1000; t++)
	{
		AES_ENC(state, exKey, 4);
	}
	QueryPerformanceCounter(&END_TIME);						// End Timer
	ELAPSED_TIME = (END_TIME.QuadPart - START_TIME.QuadPart) * 1000.0 / FREQUENCY.QuadPart;
	
	
	ELAPSED_TIME = ELAPSED_TIME / 1000; // calculate the average time

	printf("\n%s  %lf %s", "Time :", ELAPSED_TIME, "ms \n");

	printf("The chiphertext state content: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", state[i][j]);

		printf("\n");
	}

	

	AES_DEC(state, exKey, 40);
	
	printf("The plaintext state content: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", state[i][j]);

		printf("\n");
	}

	while (1)
		if (_kbhit())
			break;
}
