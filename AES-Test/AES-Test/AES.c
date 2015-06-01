#include <stdio.h>
#include <conio.h>



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



void ARK(unsigned char s[4][4], unsigned char k[4][4])
{
	int i, j;
	for (i = 0; i<4; i++)

		for (j = 0; j<4; j++)
			s[i][j] ^= k[i][j];

	/*printf("The state content after ARK transformation: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", s[i][j]);

		printf("\n");
	}*/

}



void SR(unsigned char s[4][4])
{
	int temp;


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

	//printf("The state content after Shift-Rows transformation: \n\n");


	//for (i = 0; i<4; i++)
	//{
	//	for (j = 0; j<4; j++)
	//		printf("%0.2X \t", s[i][j]);

	//	printf("\n");
	//}

}


void SB(unsigned char s[4][4])
{
	unsigned int  row, col;
	int i,j;


	unsigned char sbox[16][16] =
	{
		{ 0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76 },
		{ 0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0 },
		{ 0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15 },
		{ 0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75 },
		{ 0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84 },
		{ 0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF },
		{ 0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8 },
		{ 0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2 },
		{ 0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73 },
		{ 0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB },
		{ 0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79 },
		{ 0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08 },
		{ 0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A },
		{ 0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E },
		{ 0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF },
		{ 0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16 }
	};


	/*for (i = 0; i < 4; i++)
		printf("%0.2X \t", s[i][0]);*/

	// Sub-Byte

	//printf("The state content after sub-Bytes transformation: \n\n");
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			 

			row = (s[i][j] & 0xF0) >> 4;
			col = s[i][j] & 0x0F;


			s[i][j] = sbox[row][col];


			/*printf("%0.2X \t", s[i][j]);*/

		}
	/*	printf("\n");*/
	}
}

void keyExp(unsigned char k[4][4], unsigned char res[4][44])
{

	int i, j;
	int r, count;
	unsigned char t;
	unsigned char temp[4][4] = { { 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00 } };

	unsigned char rcon[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36 }; 
	count = 0;
	
//1st round key (col 0 - col 3)
	for (i = 3; i >= 0; i--)
		for (j = 3; j >= 0; j--)
			res[i][j] = k[i][j];

	// col 4 - col 43
	for (j = 4; j < 44; j++)
	{
		if (j % 4 == 0)
		{
			for (r = 0; r < 4; r++)
				temp[r][0] = res[r][j-1];



			/*printf("The temp content before roatate: \n\n");


			for (i = 0; i<4; i++)
			{
				for (j = 0; j<4; j++)
					printf("%0.2X \t", temp[i][j]);

				printf("\n");
			}*/
			//rotate word
			t = temp[0][0];
			temp[0][0] = temp[1][0];
			temp[1][0] = temp[2][0];
			temp[2][0] = temp[3][0];
			temp[3][0] = t;


			


			//subbyte
			SB(temp);


			
			//3XOR 
		
			for (r = 0; r < 4; r++)
				if (r == 0)
				{
			
					res[r][j] = res[r][j - 4] ^ temp[r][0] ^ rcon[count];
					count++;
				}
				else
					res[r][j] = res[r][j - 4] ^ temp[r][0];

		}//end (if j%4==0)

		else
		{
		
			// XOR
			for (r = 0; r < 4; r++)
				res[r][j] = res[r][j - 1] ^ res[r][j - 4];
		}

	

	}// end for loop

}

void MC(unsigned char s[4][4], unsigned char res[4][4])
{
	unsigned int   m[4][4] = { { 0x02, 0x03, 0x01, 0x01 },
	{ 0x01, 0x02, 0x03, 0x01 },
	{ 0x01, 0x01, 0x02, 0x03 },
	{ 0x03, 0x01, 0x01, 0x02 } };


	int c, r, k;

	for (r = 0; r < 4; r++)
		for (c = 0; c < 4; c++)
			res[r][c] = 0x00;
	

	for (c = 0; c < 4; c++)
		for (r = 0; r < 4; r++)
			for (k = 0; k<4; k++)
				res[r][c] ^= GF256multiplication(s[k][c], m[r][k]);



	

	


}



void main()
{
	int i, j, r, f,s,w;
	int col = 4;

	unsigned char state[4][4] = { { 0x32, 0x88, 0x31, 0xE0 },
	{ 0x43, 0x5A, 0x31, 0x37 },
	{ 0xF6, 0x30, 0x98, 0x07 },
	{ 0xA8, 0x8D, 0xA2, 0x34 } };

	unsigned char key[4][4] = { { 0x2B, 0x28, 0xAB, 0x09 },
	{ 0x7E, 0xAE, 0xF7, 0xCF },
	{ 0x15, 0xD2, 0x15, 0x4F },
	{ 0x16, 0xA6, 0x88, 0x3C } };

	unsigned char temp[4][4];

	unsigned char res[4][4];

	unsigned char exKey[4][44];


	printf("The input state content: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", state[i][j]);

		printf("\n");
	}

	keyExp(key,exKey);

	printf("The expanded key content: \n\n");



	for (i = 0; i < 44; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%0.2X  ", exKey[j][i]);

		printf("\n");
	}
	
	
	
	ARK(state, key);

	/*printf("The input state after first add round key content: \n\n");


	for (s = 0; s<4; s++)
	{
		for (w = 0; w<4; w++)
			printf("%0.2X \t", state[s][w]);

		printf("\n");
	}*/


	for(f = 0; f<9;f++)
	{
	   SB(state);
	  /* printf("The input state after sub byte number %d: \n\n", (f+1));


	   for (s = 0; s<4; s++)
	   {
		   for (w = 0; w<4; w++)
			   printf("%0.2X \t", state[s][w]);

		   printf("\n");
	   }*/

	   SR(state);
	   /*printf("The input state after shift row number %d: \n\n", (f + 1));


	   for (s = 0; s<4; s++)
	   {
		   for (w = 0; w<4; w++)
			   printf("%0.2X \t", state[s][w]);

		   printf("\n");
	   }*/

	    MC(state,res);
		
		for (s = 0; s < 4; s++)
			for (w = 0; w < 4; w++)
				state[s][w] = res[s][w];

		/*printf("The input state after mix column number %d: \n\n", (f + 1));


		for (s = 0; s<4; s++)
		{
			for (w = 0; w<4; w++)
				printf("%0.2X \t", state[s][w]);

			printf("\n");
		}*/
	
		for (r = 0; r < 4; r++)
		{
			for (j = 0; j < 4; j++)
			{
				temp[r][j] = exKey[r][col];
				col++;

			}
			col = col - 4;
		}
		col = col + 4;

		/*printf("The round key content: \n\n");


		for (i = 0; i<4; i++)
		{
			for (j = 0; j<4; j++)
				printf("%0.2X \t", temp[i][j]);

			printf("\n");
		}*/
		ARK(state, temp);

		/*printf("The input state after ARK number %d: \n\n", (f + 1));


		for (s = 0; s<4; s++)
		{
			for (w = 0; w<4; w++)
				printf("%0.2X \t", state[s][w]);

			printf("\n");
		}*/

	}

	SB(state);
	/*printf("The input state after last sub byte : \n\n");


	for (s = 0; s<4; s++)
	{
		for (w = 0; w<4; w++)
			printf("%0.2X \t", state[s][w]);

		printf("\n");
	}*/

	SR(state);
	/*printf("The input state after last shift row: \n\n");


	for (s = 0; s<4; s++)
	{
		for (w = 0; w<4; w++)
			printf("%0.2X \t", state[s][w]);

		printf("\n");
	}*/

	for (r = 0; r < 4; r++)
	{
		for (j = 0; j < 4; j++)
		{
			temp[r][j] = exKey[r][col];
			col++;

		}
		col = col - 4;
	}
	/*
	printf("The last round key content: \n\n");


	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
			printf("%0.2X \t", temp[i][j]);

		printf("\n");
	}*/

	ARK(state, temp);

	printf("The output state content: \n\n");


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
