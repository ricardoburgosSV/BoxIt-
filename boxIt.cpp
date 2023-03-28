#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//Implement the class Box
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box {

    private:
        int l;
        int b;
        int h;

    public:
        Box() {
            l = 0;
            b = 0;
            h = 0;
        }

        Box(int length, int breadth, int height) {
            this->l = length;
            this->b = breadth;
            this->h = height;
        }

        Box(Box &B) {
            this->l = B.l;
            this->b = B.b;
            this->h = B.h;
        }

        int getLength() {
            return this->l;
        }

        int getBreadth() {
            return this->b;
        }

        int getHeight() {
            return this->h;
        }

        long long CalculateVolume() {
        	long long nl, nb, nh;
        	nl = static_cast<long long>(this->l);
        	nb = static_cast<long long>(this->b);
        	nh = static_cast<long long>(this->h);
            return nl * nb * nh;
        }

        // Overload operator <
        bool operator<(Box& b) {
            bool ca {this->l < b.l};
            bool cb {(this->b < b.b) && (this->l == b.l)};
            bool cc {(this->h < b.h) && (this->b == b.b) && (this->l == b.l)};
            return ca || cb || cc;
        }

        // Overload operator <<
        friend ostream& operator<<(ostream& out, Box& B) {
            out<<B.l<<" "<<B.b<<" "<<B.h;
            return out;
        }

};


void check2(string fname) {
	ifstream inFil(fname);

	if (inFil) {
		int n;
		inFil>>n;
		Box temp;
		for(int i=0;i<n;i++)
		{
			int type;
			inFil>>type;
			if(type ==1)
			{
				cout<<temp<<endl;
			}
			if(type == 2)
			{
				int l,b,h;
				inFil>>l>>b>>h;
				Box NewBox(l,b,h);
				temp=NewBox;
				cout<<temp<<endl;
			}
			if(type==3)
			{
				int l,b,h;
				inFil>>l>>b>>h;
				Box NewBox(l,b,h);
				if(NewBox<temp)
				{
					cout<<"Lesser\n";
				}
				else
				{
					cout<<"Greater\n";
				}
			}
			if(type==4)
			{
				cout<<temp.CalculateVolume()<<endl;
			}
			if(type==5)
			{
				Box NewBox(temp);
				cout<<NewBox<<endl;
			}

		}

	} else {
		cout << "Error opening the file" << endl;
	}

}

int main(int argc, char *argv[]) {
	string file_name {argv[1]};
	check2(file_name);
}
