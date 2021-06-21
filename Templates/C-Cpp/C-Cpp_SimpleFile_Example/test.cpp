/*
 * @Author: Ken Kaneki
 * @Date: 2021-05-01 16:54:59
 * @LastEditTime: 2021-05-01 19:09:45
 * @Description: README
 * @FilePath: \C-Cpp_SimpleFile_Example\test.cpp
 */
#define MAX 32767       //����һ���ܴ���������ǲ�����ֱ��·���ı�־
#define N 6             //ͼ�Ķ�������
typedef struct AM_Graph //ͼ���ڽӾ�������
{
    int AdjMatrix[N][N]; //�ڽӾ����Ÿ���֮��ľ���
    int VexNum, ArcNum;  //��Ŷ��������ͻ�������
    char VexName[N];     //��������
} AM_VexName[N];         //��������
int main()
{
    int i, j;
    int dis[N][N];
    int EC[N];
    AM_Graph g;
    printf("������������������(�м�û�пո�,���Իس�������):");
    for (i = 0; i < N; i++)
        scanf("%c", &g.VexName[i]); //Ϊ�������Ƹ�ֵ��ʵ�����ڶ����������5���������˳�ӵ���һλASCII���Ӧ���ַ���Ҳ����һ���Ľ����û���������
    //  char VexName[N]={'a','b','c','d','e','f'};
    for (i = 0; i < N; i++)
    { //Ϊ���������ֱ�Ӿ��븳ֵ
        for (j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            printf("�������%d�㵽��%d��ľ���(���û��ֱ��·��������-1):", i + 1, j + 1);
            scanf("%d", &dist[i][j]);
        }
    }
    for (i = 0; i < N; i++)
    { //û��ֱ�Ӿ����ʱ��ֵΪMAX
        dist[i][i] = 0;
        for (j = 0; j < N; j++)
        {
            if (dist[i][j] < 0)
                dist[i][j] = MAX;
        }
    }
}
//���㺯��
void Floyd(AM_Graph g, int Dist[N][N])
{
    //Floyd�㷨��������֮������·�������ݵĲ���Ϊ�����ֱ��·�����ȵľ���
    printf("==============ͼ�ĸ�ֵ׼��==============\n");
    int i, j, k;
    int count = 0;
    //��¼�ߵ������������ǳ�ʼ�ľ������в���0Ҳ����MAX��Ԫ�ظ�������Ϊһ����
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if ((Dist[i][j] != 0) && (Dist[i][j] != MAX))
                count++;                    //��¼�ߵĸ���
            g.AdjMatrix[i][j] = Dist[i][j]; //�ô��ݵĶ�ά����Ϊͼ���ڽӾ���ֵ
        }
    }
    g.VexName = N; //Ϊͼ�ĸ���Ԫ�ظ�ֵ
    g.ArcNum = count;
    printGraph(g); //���ͼ�ĸ�����Ϣ���Լ����Ƿ�ֵ�ɹ�
    printf("==============Floyd�㷨���==============\n");
    for (k = 0; k < N; k++)
    { //��ͼ�е�ÿһ����Ϊ�м����dist����
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (Dist[i][j] > (Dist[i][k] + Dist[k][j]))
                {                                         //�����k��Ϊ�м����þ����С
                    Dist[i][j] = Dist[i][k] + Dist[k][j]; //�޸Ķ���֮��ľ���
                }
            }
        }
    }
}
