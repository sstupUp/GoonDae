#include <stdio.h>
#include <math.h>

#define MAX_LINE 200
#define DIMENSION_3 3
#define PI 3.14159265359

//shift cartesian Coo. to Cylindrical or Spherical

//Basic Concept was wrong
//Coordinate shift using matrix has to be used only with vectors, not with points like (1,2,4)

void toCylin(double [], double []);
void toSpher(double [], double []);
double MAC(double [], int, double [], int); 

void Cleaning_Array(char []);
int Getline(char [], int);
void Ctof(char [], double []);
void PrintData(double []);
void PrintLine(char []);

main()
{
  char buffer[MAX_LINE];
  int Mode = 0, DataInput = 0, i;
  double Data[DIMENSION_3];
  double Trans_Data[DIMENSION_3];
  
  while(DataInput >= 0)
    {
      Cleaning_Array(buffer);

      for(i = 0; i<3; ++i)
	Trans_Data[i] = 0; 

      DataInput = Getline(buffer, MAX_LINE);
      getchar();
      
      Ctof(buffer, Data);
      PrintLine("\nto Cylindrical: Enter 1\nto Spherical: Enter 2\n");
      scanf("%d", &Mode);

      if(Mode == 1)
	{
	  toCylin(Data, Trans_Data);
	  PrintLine("\n(Rho, Phi, z) =>");
	  PrintData(Trans_Data);
	}
      else if(Mode == 2)
	{
	  toSpher(Data, Trans_Data);
	  PrintLine("\n(r, Theta, Phi) =>");
	  PrintData(Trans_Data);
	}
      else
	{
	  PrintLine("\nError");
	  break;
	}

    }
}

int Getline(char s[], int lim)
{
  int c, i;

  PrintLine("Enter string:");
  
  for(i=0; i<lim-1 && (c= getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if(i == 0)
    return -1;

  if(c == '\n')
    s[i++] = '\n';

  s[i] = '\0';

  return i;
}

void Cleaning_Array(char s[])
{
  int i=0;

  for(; s[i] != '\0'; ++i)
    s[i] = 0;
}


void PrintLine(char s[])
{
  int i;

  for(i=0; s[i] != '\0'; ++i)
    putchar(s[i]);
}

void PrintData(double data[])
{
  int i=0;

  printf("\n(");
  for(; i<2; ++i)
    printf("%f, ", data[i]);

  printf("%f)\n", data[i]);
}

void Ctof(char s[], double data[])
{
  int i, j, k = 0, sign, point;
  double ans;

  j = 0;
  
  sign = 1;
  point = 0; 

  ans = 0;
  
  for(i=0; s[i] != '\0'; ++i)
    if(s[i] == '-' || s[i] == '+')
      sign = (s[i] == '-') ? -1 : 1;
    else if(s[i] >= '0' && s[i] <= '9')
      ans = ans*10 + (s[i] - '0');
    else if(s[i] == '.')
      point = i;
    else if(s[i] == ',' || s[i] == ')')
      {
	if(point > 0)
	  {
	    point = i - point;
	    for(j = 0; j<point; ++j)
	      ans /= 10;
	  }
	
	data[k++] = ans*sign;
	ans = 0;
      }
    else
      continue;
}

double MAC(double mat1[], int size1, double mat2[], int size2)
{
  int i;
  double ans=0;
  
  for(i = 0; i<size1; ++i)
    ans = ans + mat1[i]*mat2[i];

  return ans;
}

void toCylin(double data[], double changed[])
{
  int i, j;
  double Phi = atan(data[1]/data[0]);
  double Cylin_Matrix[DIMENSION_3][DIMENSION_3] = { {cos(Phi), sin(Phi), 0},
						    {-sin(Phi), cos(Phi) ,0},
						    {0, 0, 1}};

  for(i =0; i<3; ++i)
    changed[i] = MAC(Cylin_Matrix[i], 3, data, 3);
}

void toSpher(double data[], double changed[])
{
 int i, j;
 double Phi = atan(data[1]/data[0]), Theta = atan(sqrt(data[0]*data[0] + data[1]*data[1])/data[2]);
 
 double Cylin_Matrix[DIMENSION_3][DIMENSION_3] = { {sin(Theta)*cos(Phi), sin(Theta)*sin(Phi), cos(Theta)},
						   {cos(Theta)*cos(Theta), cos(Theta)*sin(Phi), -sin(Theta)},
						   {-sin(Phi), cos(Phi), 0}};

  for(i =0; i<3; ++i)
    changed[i] = MAC(Cylin_Matrix[i], 3, data, 3);
}
