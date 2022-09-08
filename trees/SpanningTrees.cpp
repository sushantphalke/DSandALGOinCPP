#include<iostream>
#include<vector>
using namespace std;

class SpaningTree
{
    int v,e,w;
    int **adjMatrix;
    int * visited;
    public :
    SpaningTree(int v,int e);
    void addEdge(int start,int e,int weight);
    void minimumTree();
    void printAdjMatrix();
};

SpaningTree::SpaningTree(int v,int e)
{
    this->v = v;
    this->e = e;
    adjMatrix = new int*[v];
    visited = new int[v];
    for(int row = 0 ; row < v; row++)
    {
        visited[row] = 0;
        adjMatrix[row] = new int[v];
        for(int column = 0;column < v; column++)
        {
            adjMatrix[row][column] = 999; 
        }
    }
}

void SpaningTree::addEdge(int start,int e,int weight)
{
    adjMatrix[start][e] = weight;
    adjMatrix[e][start] = weight;
}

void SpaningTree::printAdjMatrix(){
     for(int row = 0 ; row < v; row++){
        for(int column = 0;column < v; column++)
        { cout<<adjMatrix[row][column]<<"\t";   }
        cout<<endl;
 }}

void SpaningTree::minimumTree()
{
    int p=0,q=0,total=0,min;
    visited[0] = 1;
	for(int count=0;count<(v-1);count++)
	{
		min=999;
		for(int i=0;i<v;i++)
		{
			if(visited[i]==1)
			{
				for(int j=0;j<v;j++)
				{
					if(visited[j]!=1)
					{
						if(min > adjMatrix[i][j])
					{
							min=adjMatrix[i][j];
							p=i;
							q=j;}}}}}
		visited[p]=1;
		visited[q]=1;
		total=total+min;
		cout<<"Minimum cost connection is "<<(p)<<" -> "<<(q)<<"  with charge : "<<min<< endl;
	}
	cout<<"The minimum total cost of connections of all branches is: "<<total<<endl;
}


int main(void){
    SpaningTree st = SpaningTree(5,7);
   
    st.addEdge(0,1,200);
    st.addEdge(0,3,600);
    st.addEdge(1,2,300);
    st.addEdge(1,4,500);
    st.addEdge(2,4,700);
    st.addEdge(3,4,900);
    cout<<endl<<endl;
    st.minimumTree();}
