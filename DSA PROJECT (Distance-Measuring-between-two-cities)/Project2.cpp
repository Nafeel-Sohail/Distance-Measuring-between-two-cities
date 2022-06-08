#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
#include<queue>
#include<functional>
#include <limits>

using namespace std;

# define INF 0x3f3f3f3f 
// iPair ==> Integer Pair 
typedef pair<int, int> iPair;
// To add an edge 
void Edge(vector <pair<int, int> > adj[], int u, int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

void ignoreLine()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prints shortest paths from source to all other vertices 
void Shortest_path_finder(vector<pair<int, int> > adj[], int V, int des, int src, int number, double speed)
{
	priority_queue< iPair, vector <iPair>, greater<iPair> > pq;
	vector<int> dist(V, INF);
	 /*int table [10][2];*/
	int k = src;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	/*for (int i = 0; i < 10; i++)
	{
		table[i][0] = i;
		table[i][1] = INF;
	}*/
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first;
			int weight = adj[u][i].second;
			if (dist[v] > dist[u] + weight)
			{
				/*table[v][1] = u;*/
				dist[v] = dist[u] + weight;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	/*cout << source << endl;
	while (source != destination)
	{
		for (int i = 0; i < size; i++)
		{
			if (source == table[i][1] && dist[destination] >= dist[source])
			{
				source = i;
				cout << source << endl;
				break;
			}
		}
	}*/
	cout << "\n\t   ---------------------------------------------------------------------------";
	if (number == 1 || number == 2)
	{
		for (int i = 0; i <= 0; ++i)
		{
			cout << "\n\n\t    VERTEX DISTANCE FROM SOURCE NODE " << k << " ---> " << " TO DESTINATION NODE " << des << " IS " << dist[des] << " KM." << endl << endl;
		}
		cout << "\t   ---------------------------------------------------------------------------\n\n";
	}
	else if (number == 3 || number == 4)
	{
		for (int i = 0; i <= 0; ++i)
		{
			cout << "\n\n\t    VERTEX TIME FROM SOURCE NODE " << k << " ---> " << " TO DESTINATION NODE " << des << " IS " << (dist[des]/speed)*60 << " MIN" << endl << endl;
		}
		cout << "\t   ---------------------------------------------------------------------------\n\n";
	}
}
struct subnode
{
	string city;
	int weight=0;
};
struct Node
{
	string city;
	vector<subnode> links;
};

int main()
{
	int n;
	const int size = 10;
	const int num_size = 17;
	ifstream text;
	string  name_of_countries[size];
	int weight_of_countries[num_size];
	string c[size];
	c[0] = "Multan.txt", c[1] = "Bahawalpur.txt", c[2] = "Lahore.txt", c[3] = "Islamabad.txt", c[4] = "Karachi.txt";
	c[5] = "Quetta.txt", c[6] = "Peshawar.txt", c[7] = "Murree.txt", c[8] = "Naran.txt", c[9] = "Faisalabad.txt";
	text.open("Country names.txt", ios::in);
	if (!text)
	{
		cout << "\tFILE DOES NOT EXIST";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			getline(text, name_of_countries[i]);
		}
		for (int i = 0; i < num_size; i++)
		{
			text >> weight_of_countries[i];
		}
		/*for (int i = 0; i < size; i++)
		{
			cout << name_of_countries[i] << endl;
		}
		for (int i = 0; i < num_size; i++)
		{
			cout << weight_of_countries[i] << endl;
		}*/
	}
	text.close();
	system("CLS");
again:
	cout << "\n\n\t------------------------------- WELCOME TO THE MAP AND ROUTE PLANNER -------------------------------\n" << endl;
	again_error1:
	cout << "\n\tPRESS 1 TO FIND DISTANCE BETWEEN INTER CITIES MAP" << endl;
	cout << "\n\tPRESS 2 TO FIND DISTANCE BETWEEN INTRA CITIES MAP" << endl;
	cout << "\n\tPRESS 3 TO FIND TIME BETWEEN INTER CITIES MAP" << endl;
	cout << "\n\tPRESS 4 TO FIND TIME BETWEEN INTRA CITIES MAP" << endl;
	cout << "\n\tPRESS 0 TO EXIT" << endl;
	cout << "\n\t\tENTER THE REQUIRED INPUT: ";
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		ignoreLine();
		goto again_end;
	}
	if (n == 1 || n == 2 || n == 0 || n == 3 || n == 4)
	{
		text.open("Country names.txt", ios::in);
		if (!text)
		{
			cout << "\tFILE DOES NOT EXIST";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				getline(text, name_of_countries[i]);
			}
			for (int i = 0; i < num_size; i++)
			{
				text >> weight_of_countries[i];
			}
			/*for (int i = 0; i < size; i++)
			{
				cout << name_of_countries[i] << endl;
			}
			for (int i = 0; i < num_size; i++)
			{
				cout << weight_of_countries[i] << endl;
			}*/
		}
		text.close();
		system("CLS");
		if (n == 1 || n == 3)
		{
			cout << "\n     ------------------------------- WELCOME TO THE INTER CITY MAP AND ROUTE PLANNER -------------------------------\n" << endl;
			cout << "\n\n\n";
		again_data:
			vector<Node> graph;//for cities
			Node place_0, place_1, place_2, place_3, place_4, place_5, place_6, place_7, place_8, place_9;
			subnode p0_p1, p0_p2;  //0
			subnode p1_p0, p1_p2, p1_p3, p1_p4, p1_p5;     //1
			subnode p2_p0, p2_p1, p2_p3, p2_p6, p2_p8, p2_p9;;	//2
			subnode p3_p1, p3_p2;	//3
			subnode p4_p1, p4_p5, p4_p7; //4
			subnode p5_p1, p5_p4, p5_p6;	//5
			subnode p6_p2, p6_p5, p6_p7, p6_p9;	//6
			subnode p7_p4, p7_p6, p7_p9;	//7
			subnode p8_p2, p8_p9;	//8
			subnode p9_p2, p9_p6, p9_p7, p9_p8;	//9

			place_0.city = name_of_countries[0];
			place_1.city = name_of_countries[1];
			place_2.city = name_of_countries[2];
			place_3.city = name_of_countries[3];
			place_4.city = name_of_countries[4];
			place_5.city = name_of_countries[5];
			place_6.city = name_of_countries[6];
			place_7.city = name_of_countries[7];
			place_8.city = name_of_countries[8];
			place_9.city = name_of_countries[9];
			//cout << place_0.city << place_1.city << place_2.city << place_3.city << place_4.city << place_5.city << place_6.city << place_7.city << place_8.city << place_9.city ;

			p0_p1.city = name_of_countries[1];
			p0_p1.weight = weight_of_countries[0];
			p0_p2.city = name_of_countries[2];
			p0_p2.weight = weight_of_countries[1];
			place_0.links.push_back(p0_p1);
			place_0.links.push_back(p0_p2);
			graph.push_back(place_0);

			p1_p0.city = name_of_countries[0];
			p1_p0.weight = weight_of_countries[0];
			p1_p2.city = name_of_countries[2];
			p1_p2.weight = weight_of_countries[2];
			p1_p3.city = name_of_countries[3];
			p1_p3.weight = weight_of_countries[3];
			p1_p4.city = name_of_countries[4];
			p1_p4.weight = weight_of_countries[4];
			p1_p5.city = name_of_countries[5];
			p1_p5.weight = weight_of_countries[5];
			place_1.links.push_back(p1_p0);
			place_1.links.push_back(p1_p2);
			place_1.links.push_back(p1_p3);
			place_1.links.push_back(p1_p5);
			place_1.links.push_back(p1_p4);
			graph.push_back(place_1);

			p2_p0.city = name_of_countries[0];
			p2_p0.weight = weight_of_countries[1];
			p2_p1.city = name_of_countries[1];
			p2_p1.weight = weight_of_countries[2];
			p2_p3.city = name_of_countries[3];
			p2_p3.weight = weight_of_countries[6];
			p2_p6.city = name_of_countries[6];
			p2_p6.weight = weight_of_countries[7];
			p2_p8.city = name_of_countries[8];
			p2_p8.weight = weight_of_countries[8];
			p2_p9.city = name_of_countries[9];
			p2_p9.weight = weight_of_countries[9];
			place_2.links.push_back(p2_p0);
			place_2.links.push_back(p2_p1);
			place_2.links.push_back(p2_p3);
			place_2.links.push_back(p2_p6);
			place_2.links.push_back(p2_p8);
			place_2.links.push_back(p2_p9);
			graph.push_back(place_2);

			p3_p1.city = name_of_countries[1];
			p3_p1.weight = weight_of_countries[3];
			p3_p2.city = name_of_countries[2];
			p3_p2.weight = weight_of_countries[6];
			place_3.links.push_back(p3_p1);
			place_3.links.push_back(p3_p2);
			graph.push_back(place_3);

			p4_p1.city = name_of_countries[1];
			p4_p1.weight = weight_of_countries[4];
			p4_p5.city = name_of_countries[5];
			p4_p5.weight = weight_of_countries[10];
			p4_p7.city = name_of_countries[7];
			p4_p7.weight = weight_of_countries[11];
			place_4.links.push_back(p4_p1);
			place_4.links.push_back(p4_p5);
			place_4.links.push_back(p4_p7);
			graph.push_back(place_4);

			p5_p1.city = name_of_countries[1];
			p5_p1.weight = weight_of_countries[5];
			p5_p4.city = name_of_countries[4];
			p5_p4.weight = weight_of_countries[10];
			p5_p6.city = name_of_countries[6];
			p5_p6.weight = weight_of_countries[12];
			place_5.links.push_back(p5_p1);
			place_5.links.push_back(p5_p4);
			place_5.links.push_back(p5_p6);
			graph.push_back(place_5);

			p6_p2.city = name_of_countries[2];
			p6_p2.weight = weight_of_countries[7];
			p6_p5.city = name_of_countries[5];
			p6_p5.weight = weight_of_countries[12];
			p6_p7.city = name_of_countries[7];
			p6_p7.weight = weight_of_countries[13];
			p6_p9.city = name_of_countries[9];
			p6_p9.weight = weight_of_countries[16];
			place_6.links.push_back(p6_p2);
			place_6.links.push_back(p6_p5);
			place_6.links.push_back(p6_p7);
			place_6.links.push_back(p6_p9);
			graph.push_back(place_6);

			p7_p4.city = name_of_countries[4];
			p7_p4.weight = weight_of_countries[11];
			p7_p6.city = name_of_countries[6];
			p7_p6.weight = weight_of_countries[13];
			p7_p9.city = name_of_countries[9];
			p7_p9.weight = weight_of_countries[14];
			place_7.links.push_back(p7_p4);
			place_7.links.push_back(p7_p6);
			place_7.links.push_back(p7_p9);
			graph.push_back(place_7);

			p8_p2.city = name_of_countries[2];
			p8_p2.weight = weight_of_countries[8];
			p8_p9.city = name_of_countries[9];
			p8_p9.weight = weight_of_countries[15];
			place_8.links.push_back(p8_p2);
			place_8.links.push_back(p8_p9);
			graph.push_back(place_8);

			p9_p2.city = name_of_countries[2];
			p9_p2.weight = weight_of_countries[9];
			p9_p6.city = name_of_countries[6];
			p9_p6.weight = weight_of_countries[16];
			p9_p7.city = name_of_countries[7];
			p9_p7.weight = weight_of_countries[14];
			p9_p8.city = name_of_countries[8];
			p9_p8.weight = weight_of_countries[15];
			place_9.links.push_back(p9_p2);
			place_9.links.push_back(p9_p6);
			place_9.links.push_back(p9_p7);
			place_9.links.push_back(p9_p8);
			graph.push_back(place_9);



			for (int j = 0; j < graph.size(); j++)
			{
				cout << "\n\t\t\t\t\t" << graph[j].city << " ROUTE TO OTHER LINK CITIES\n";
				cout << "\t\t\t\t ---------------------------------------------------------\n\n\n";
				for (int i = 0; i < graph[j].links.size(); i++)
				{
					cout << "    " << graph[j].city << " ---> " << graph[j].links[i].city << " IS " << " " << graph[j].links[i].weight << " KM \n" << endl;
				}
				cout << endl;
			}


			int source, destination, loop;
			double time = 0;
			const int size = 10;
			vector<iPair > adj[size];
			Edge(adj, 0, 1, weight_of_countries[0]);
			Edge(adj, 0, 2, weight_of_countries[1]);
			Edge(adj, 1, 2, weight_of_countries[2]);
			Edge(adj, 1, 3, weight_of_countries[3]);
			Edge(adj, 1, 4, weight_of_countries[4]);
			Edge(adj, 1, 5, weight_of_countries[5]);
			Edge(adj, 2, 3, weight_of_countries[6]);
			Edge(adj, 2, 6, weight_of_countries[7]);
			Edge(adj, 2, 8, weight_of_countries[8]);
			Edge(adj, 2, 9, weight_of_countries[9]);
			Edge(adj, 4, 5, weight_of_countries[10]);
			Edge(adj, 4, 7, weight_of_countries[11]);
			Edge(adj, 5, 6, weight_of_countries[12]);
			Edge(adj, 6, 7, weight_of_countries[13]);
			Edge(adj, 6, 9, weight_of_countries[16]);
			Edge(adj, 7, 9, weight_of_countries[14]);
			Edge(adj, 8, 9, weight_of_countries[15]);

		again_inter:
			cout << "\n    PRESS 1 TO RUN THIS PROGRAM" << endl;
			cout << "\n    PRESS 2 TO RETURN TO THE MAIN PAGE" << endl;
			cout << "\n    PRESS 0 TO EXIT THIS PROGRAM" << endl;
			cout << "\n\n\t   ENTER THE REQUIRED INPUT: ";
			cin >> loop;
			if (cin.fail())
			{
				cin.clear();
				ignoreLine();
				goto again_inter_1;
			}
			if (loop == 0 || loop == 1 || loop == 2)
			{
				system("CLS");
				while (loop == 1)
				{
					cout << "\n     ------------------------------- WELCOME TO THE INTER CITY MAP AND ROUTE PLANNER -------------------------------\n\n" << endl;
					cout << "   PRESS 0 TO SELECT CITY OF " << name_of_countries[0] << endl << endl;
					cout << "   PRESS 1 TO SELECT CITY OF " << name_of_countries[1] << endl << endl;
					cout << "   PRESS 2 TO SELECT CITY OF " << name_of_countries[2] << endl << endl;
					cout << "   PRESS 3 TO SELECT CITY OF " << name_of_countries[3] << endl << endl;
					cout << "   PRESS 4 TO SELECT CITY OF " << name_of_countries[4] << endl << endl;
					cout << "   PRESS 5 TO SELECT CITY OF " << name_of_countries[5] << endl << endl;
					cout << "   PRESS 6 TO SELECT CITY OF " << name_of_countries[6] << endl << endl;
					cout << "   PRESS 7 TO SELECT CITY OF " << name_of_countries[7] << endl << endl;
					cout << "   PRESS 8 TO SELECT CITY OF " << name_of_countries[8] << endl << endl;
					cout << "   PRESS 9 TO SELECT CITY OF " << name_of_countries[9] << endl << endl;

				again_source:
					cout << "  ENTER THE REQUIRED SOURCE NODE INPUT: ";
					cin >> source;
					if (cin.fail())
					{
						cin.clear();
						ignoreLine();
						goto again_source_1;
					}
					cout << "\n  YOUR SOURCE NODE: " << source << endl;
					if (source >= 0 && source < 10)
					{
					again_dest:
						cout << "\n  KINDLY ENTER THE REQUIRED DESTINATION NODE INPUT: ";
						cin >> destination;
						if (cin.fail())
						{
							cin.clear();
							ignoreLine();
							goto again_dest_1;
						}
						if (n == 3 || n == 4)
						{
							cout << "\n  KINDLY ENTER THE AVERAGE SPEED AT WHICH YOU ARE TRAVELLING: ";
							cin >> time;
						}
						if (destination >= 0 && destination < 10)
						{
							Shortest_path_finder(adj, size, destination, source,n,time);
							goto again_inter;
						}
						else
						{
							again_dest_1:
							cout << "  YOUR DESINATION NODE DOES NOT EXIST" << endl;
							cout << "\n  KINDLY RE-ENTER THE DESINATION NODE\n\n" << endl;
							goto again_dest;
						}
					}
					else
					{
						again_source_1:
						cout << "  YOUR SOURCE NODE DOES NOT EXIST" << endl;
						cout << "\n  KINDLY RE-ENTER THE SOURCE NODE\n\n" << endl;
						goto again_source;
					}
				}
				while (loop == 2)
				{
					goto again;
				}
				while (loop == 0)
				{
					exit(0);
					system("Pause");
				}
			}
			else
			{
				again_inter_1:
				cout << "\n\t\tYOU HAVE ENTERD WRONG INPUT. KINDLY SELECT THE CORRECT INPUT.\n\n";
				goto again_inter;
			}
		}

		if (n == 2 || n == 4);
		{
			cout << "\n     ------------------------------- WELCOME TO THE INTRA CITY MAP AND ROUTE PLANNER -------------------------------\n\n" << endl;
			int m;
			again_intra:
			cout << "   PRESS 0 FOR " << name_of_countries[0] << endl << endl;
			cout << "   PRESS 1 FOR " << name_of_countries[1] << endl << endl;
			cout << "   PRESS 2 FOR " << name_of_countries[2] << endl << endl;
			cout << "   PRESS 3 FOR " << name_of_countries[3] << endl << endl;
			cout << "   PRESS 4 FOR " << name_of_countries[4] << endl << endl;
			cout << "   PRESS 5 FOR " << name_of_countries[5] << endl << endl;
			cout << "   PRESS 6 FOR " << name_of_countries[6] << endl << endl;
			cout << "   PRESS 7 FOR " << name_of_countries[7] << endl << endl;
			cout << "   PRESS 8 FOR " << name_of_countries[8] << endl << endl;
			cout << "   PRESS 9 FOR " << name_of_countries[9] << endl << endl;
			cout << "   PRESS 10 TO RETURN TO MAIN PAGE \n" << endl;
			cout << "   PRESS 20 TO EXIT \n" << endl;
			cout << "\n\t\tENTER THE REQUIRED INPUT: ";
			cin >> m;
			if (cin.fail())
			{
				cin.clear();
				ignoreLine();
				goto again_intra_1;
			}
			if (m <= 10 && m >= 0 || m == 20)
			{
				system("CLS");
				if (m == 0)
				{
				again_outlook:
					cout << "\n     ------------------------------- WELCOME TO THE " << name_of_countries[m] << " CITY MAP AND ROUTE PLANNER -------------------------------\n" << endl;
					cout << "\n\n\n";
					text.open(c[m], ios::in);
					if (!text)
					{
						cout << "\tFILE DOES NOT EXIST";
					}
					else
					{
						for (int i = 0; i < size; i++)
						{
							getline(text, name_of_countries[i]);
						}
						for (int i = 0; i < num_size; i++)
						{
							text >> weight_of_countries[i];
						}
						/*for (int i = 0; i < size; i++)
						{
							cout << name_of_countries[i] << endl;
						}
						for (int i = 0; i < num_size; i++)
						{
							cout << weight_of_countries[i] << endl;
						}*/
					}
					text.close();
					goto again_data;
				}
				if (m == 1)
				{
					goto again_outlook;
				}
				if (m == 2)
				{
					goto again_outlook;
				}
				if (m == 3)
				{
					goto again_outlook;
				}
				if (m == 4)
				{
					goto again_outlook;
				}
				if (m == 5)
				{
					goto again_outlook;
				}
				if (m == 6)
				{
					goto again_outlook;
				}
				if (m == 7)
				{
					goto again_outlook;
				}
				if (m == 8)
				{
					goto again_outlook;
				}
				if (m == 9)
				{
					goto again_outlook;
				}
				if (m == 20)
				{
					exit(0);
					system("Pause");
				}
				if (m == 10)
				{
					goto again;
				}
			}
			else
			{
				again_intra_1:
				cout << "\n\t\tYOU HAVE ENTERD WRONG INPUT. KINDLY SELECT THE CORRECT INPUT.\n\n";
				goto again_intra;
			}
		}
		system("CLS");
		if (n == 0)
		{
			exit(0);
			system("Pause");
		}
	}
	else
	{
	again_end:
	cout << "\n\t\tYOU HAVE ENTERD WRONG INPUT. KINDLY SELECT THE CORRECT INPUT.\n\n";
	goto again_error1;
	}
}

