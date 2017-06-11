#include "myalg.h"

TEST(DeleteSubStringTest, Demo)
{
	char *str = "abcde123abcd123";
	char *sub_str = "123";
	char *res_str = new char[100];
	int subnum = DeleteSubStr(str, sub_str, res_str);

	EXPECT_EQ(2, subnum);
	EXPECT_STREQ("abcdeabcd", res_str);
}

TEST(PassLineTest, Demo)
{
	float a1[10] = { 73.6, 85.5, 97.3, 30.2, 40.3, 50.4, 60.5, 70.6, 80.5, 90.3};
	float a2[10] = { 3.6, 5.5, 7.3, 0.2, 0.3, 0.4, 0.5, 0.6, 0.5, 0.3};
	float a3[10] = { 13.6, 15.5, 17.3, 10.2, 10.3, 10.4, 60.5, 70.6, 80.5, 10.3};
	float a4[10] = { 73.6, 85.5, 97.3, 63.2, 85.3, 64.4, 60.5, 70.6, 80.5, 90.3};
	float a5[10] = { 50,50,50,50,50,30,30,40,40,50};

	EXPECT_EQ(70, PassLine(a1, 10));
	EXPECT_EQ(0, PassLine(a2, 10));
	EXPECT_EQ(10, PassLine(a3, 10));
	EXPECT_EQ(60, PassLine(a4, 10));
	EXPECT_EQ(50, PassLine(a5, 10));
}

TEST(LineNumTest, Demo)
{
	EXPECT_EQ(1, Lights(3));
	EXPECT_EQ(2, Lights(5));
	EXPECT_EQ(3, Lights(10));
	EXPECT_EQ(10, Lights(100));
}

TEST(StringFilterTest, Demo)
{
	char pInputStr1[] = { "afafafafpppppppppppppp" };
	char pInputStr2[] = { "cccdppppppppppppppppdecccccccccccccccccccccc" };
	char pInputStr3[] = { "355 - 4555" };
	char pOutputStr1[256] = { 0 };
	char pOutputStr2[256] = { 0 };
	char pOutputStr3[256] = { 0 };
	StringFilter(pInputStr1, strlen(pInputStr1), pOutputStr1);
	StringZip(pInputStr2, strlen(pInputStr2), pOutputStr2);
	CharIntegerOperation(pInputStr3, strlen(pInputStr3), pOutputStr3);

	EXPECT_STREQ("afp", pOutputStr1 );
	EXPECT_STREQ("3cd16pde22c", pOutputStr2 );
	//EXPECT_STREQ("0", pOutputStr3 );
}

TEST(TreeTest, Demo)
{
	BTNode *b;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("层次遍历:");  TravLevel(b);
	printf("先序遍历:");  PreOrder(b);
	printf("中序遍历:");  InOrder(b);
	printf("后序遍历:");  PostOrder(b);
	printf("二叉树b的宽度:%d\n", BTWidth(b));
	vector<ElemType> path;
	vector<ElemType> longpath;
	AllPathRecursion(b, path);
	AllPath(b);
	LongPath(b, path, longpath);
	printf("\n第一条最长路径长度：%d\n", longpath.size());
	printf("第一条最长路径:");
	for (int i = longpath.size() - 1; i >= 0; i--)
		printf("%c ", longpath[i]);
	printf("\n");

	EXPECT_EQ(4, BTWidth(b));
	EXPECT_EQ(7, longpath.size() );
}

TEST(DFSBFSTest, Demo)
{
	size_t i, j;
	MGraph g;
	ALGraph *G = new ALGraph;
	int A[MAXV][6] = {
		{ 0, 5, 0, 7, 0, 0 },
		{ 0, 0, 4, 0, 0, 0 },
		{ 8, 0, 0, 0, 0, 9 },
		{ 0, 0, 5, 0, 0, 6 },
		{ 0, 0, 0, 5, 0, 0 },
		{ 3, 0, 0, 0, 1, 0 }
	};
	g.n = 6;
	g.e = 10;
	for (i = 0; i<g.n; ++i)
	for (j = 0; j<g.n; ++j)
		g.edges[i][j] = A[i][j];
	printf(" 有向图G的邻接矩阵：\n");	DispMat(g);
	MatToList(g, G);
	printf(" 有向图G的邻接矩阵转换为邻接表：\n");	DispAdj(G);
	printf("从顶点0开始的DFS:\n");
	DFS(G, 0); printf("\n");
	printf("从顶点0开始的DFS1:\n");
	DFS1(G, 0); printf("\n");
	printf("从顶点0开始的BFS:\n");
	BFS(G, 0); printf("\n");
}

TEST(DijkstraTest, Demo)
{
	//总是弹出栈溢出，有待解决

	//int i, j, u(0);
	//MGraph g;
	//int A[MAXV][6] = {
	//	{ INF, 5, INF, 7, INF, INF },
	//	{ INF, INF, 4, INF, INF, INF },
	//	{ 8, INF, INF, INF, INF, 9 },
	//	{ INF, INF, 5, INF, INF, 6 },
	//	{ INF, INF, INF, 5, INF, INF },
	//	{ 3, INF, INF, INF, 1, INF },
	//};
	//g.n = 6;
	//g.e = 10;
	//for (i = 0; i<g.n; ++i)
	//for (j = 0; j<g.n; ++j)
	//	g.edges[i][j] = A[i][j];
	//printf("\n");
	//printf("有向图G的邻接矩阵：\n");
	//DispMat(g);
	//Dijkstra(g, u);
	////Flyod(g);
	//printf("\n");
}


TEST(FlyodTest, Demo)
{
	MGraph g;
	g.n = 35;
	g.e = 35;
	for (int i = 0; i < g.n; ++i)
	for (int j = 0; j < g.n; ++j){
		if (i == j) g.edges[i][j] = 0;
		else g.edges[i][j] = INF;
	}
	//输入A环线个点相连情况 每个边权重都为1
	int a[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 33, 9, 10, 11, 12, 34, 13, 14, 15, 16, 17, 0 };
	for (int i = 0; i < 20; ++i){
		g.edges[a[i]][a[i + 1]] = 1;
		g.edges[a[i + 1]][a[i]] = 1;
	}
	//输入B线个点相连情况 每个边权重都为1
	int b[17] = { 18, 29, 20, 21, 22, 33, 23, 24, 25, 26, 27, 34, 28, 29, 30, 31, 32 };
	for (int i = 0; i < 16; i++){
		g.edges[b[i]][b[i + 1]] = 1;
		g.edges[b[i + 1]][b[i]] = 1;
	}
	std::vector<std::vector<int> > A(MAXV, std::vector<int>(MAXV, 0));
	Flyod(g, A);
	//string startport, endport;
	//while (true)
	//{
	//	cout << "输入起点和终点站，如(A1 B10):";
	//	cin >> startport >> endport;
	//	if (char2int(startport) != -1 && char2int(endport) != -1)
	//		cout << A[char2int(startport)][char2int(endport)] << endl;
	//	else cout << "Input Error!" << endl;
	//}

	EXPECT_EQ(7, A[Char2Int("A1")][Char2Int("B10")]);
	EXPECT_EQ(8, A[Char2Int("A1")][Char2Int("B12")]);
}

TEST(KruskalTest, Demo)
{
	int i, j;
	MGraph g;
	Edge E[MAXE];
	int A[MAXV][11];
	g.n = 6;
	g.e = 10;
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		A[i][j] = INF;
	A[0][1] = 5; A[0][2] = 8; A[0][3] = 7; A[0][5] = 3;
	A[1][2] = 4;
	A[2][3] = 5; A[2][5] = 9;
	A[3][4] = 5;
	A[4][5] = 1;
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		A[j][i] = A[i][j];
	for (i = 0; i<g.n; i++)
	for (j = 0; j<g.n; j++)
		g.edges[i][j] = A[i][j];
	SortEdge(g, E);

	cout << endl;
	cout << "图的邻接矩阵:" << endl;
	DispMat(g);
	cout << "克鲁斯卡尔算法求解结果：" << endl;
	Kruskal(E, g.n, g.e);
	cout<<endl;
}
