#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Move(char* p, size_t len,int num)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (p[i] <= 'z' && p[i] >= 'a')
        {
            p[i] = (char)('a' + (p[i] - 'a' + num) % 26);             /*�ؼ��㣺
                                                                      ����Сд��ĸ���Ǿ�ֱ�Ӽ������롮a���Ĳ�ֵ���õ���ֵ�� % 26���õ������������϶�Ӧ�����֣���ĸ����
                                                                      ����ʱ�һ�Ҫ�ٰ���ת���ɶ�Ӧ��ascii���ַ��������ټ��� 'a',֮��Ϳ�����ȷ��ӡ��Ӧ�ַ��ˡ�
                                                                        */
        }
        else if (p[i] <= 'Z' && p[i] >= 'A')
        {
            //�ؼ��㣺 ���Ǵ�д��ĸ���Ǿ�ֱ�Ӽ������롮A���Ĳ�ֵ���õ���ֵ�� % 26���õ����������۵Ķ�Ӧ�����֣���ĸ����
            p[i] = (char)('A' + (p[i] - 'A'+num) % 26);                //����ʱ�һ�Ҫ�ٰ���ת���ɶ�Ӧ��ascii���ַ��������ټ��� 'A',֮��Ϳ�����ȷ��ӡ��Ӧ�ַ��ˡ�           

        }
    }

}
int main() {
    char a[100] = { 0 };
    fgets(a, 100, stdin);
    int len = strlen(a);
    if (a[len - 1] == '\n')
    {
        a[len - 1] == '\0';
        len--;
    }

    int num = 0;
    scanf("%d", &num);
    Move(a, len,num);
    printf("%s", a);

    return 0;
}