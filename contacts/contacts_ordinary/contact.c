#include "contact.h"

void InitContact(struct Contact *ps)
{
  memset(ps->data, 0, sizeof (ps->data));
  ps->size = 0;//设置通讯录最初只有0个元素
}

void AddContact(struct Contact *ps)
{
  if (ps->size == MAX)
  {
    printf("通讯录已满，无法增加\n");
  }
  else
  {
    printf("请输入姓名:>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄:>");
    scanf("%d", &(ps->data[ps->size].age));
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].gender);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址:>");
    scanf("%s", ps->data[ps->size].addr);

    ps->size++;
    printf("添加成功!\n");
  }
}

void ShowContact(const struct Contact *ps)
{
  if (ps->size == 0)
  {
    printf("通讯录为空\n");
  }
  else
  {
    int i = 0;
    printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
    for (i=0; i<ps->size; i++)
    {
      printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
          ps->data[i].name,
          ps->data[i].age,
          ps->data[i].gender,
          ps->data[i].tele,
          ps->data[i].addr);
    }
  }
}

static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
  int i = 0;
  for (i=0; i<ps->size; i++)
  {
    if(0 == strcmp(ps->data[i].name, name))
    {
      return i;// 找到了
    }
  }
  return -1;//找不到
}

void DelContact(struct Contact *ps)
{
  if (ps->size == 0)
  {
    printf("通讯录为空，无法删除\n");
  }
  else
  {
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    //1.查找要删除的人在什么位置
    // 找到了返回下标
    // 找不到返回-1,下标中无-1
    int pos = FindByName(ps, name);
    //2.删除
    if (pos == -1)
    {
      printf("要删除的人不存在\n");
    }
    else
    {
      int j = 0;
      for (j=pos; j<ps->size-1; j++)
      {
        ps->data[j] = ps->data[j+1];
      }
      ps->size--;
      printf("删除成功!\n");
     
     }

  }
}

void SearchContact(const struct Contact *ps)
{
  if (ps->size == 0)
  {
    printf("通讯录为空，无法查找\n");
  }
  else
  {
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (-1 == pos)
    {
      printf("要查找的人不存在\n");
    }
    else
    {
      printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
      printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
          ps->data[pos].name,
          ps->data[pos].age,
          ps->data[pos].gender,
          ps->data[pos].tele,
          ps->data[pos].addr);

    }
  }
}

void ModifyContact(struct Contact *ps)
{
  if (ps->size == 0)
  {
    printf("通讯录为空，无法进行修改\n");
  }
  else
  {
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (pos == -1)
    {
      printf("要修改人的信息不存在\n");
    }
    else
    {
      printf("请输入姓名:>");
      scanf("%s", ps->data[pos].name);
      printf("请输入年龄:>");
      scanf("%d", &(ps->data[pos].age));
      printf("请输入性别:>");
      scanf("%s", ps->data[pos].gender);
      printf("请输入电话:>");
      scanf("%s", ps->data[pos].tele);
      printf("请输入地址:>");
      scanf("%s", ps->data[pos].addr);
      
      printf("修改完成!\n");
    }
  }
}

static int SortByName(const void *e1, const void *e2)
{
  return strcmp(((struct PeoInfo*)e1)->name, ((struct PeoInfo*)e2)->name);
}

void BubbleSort()
{

}

void SortContact(struct Contact *ps)
{
  if (NULL == ps)
  {
    perror("SortContact()");
    return;
  }
  else if (ps->size == 0)
  {
    printf("通讯录为空,无法排序!\n");
  }
  else
  {
    qsort(ps->data, ps->size, sizeof(struct PeoInfo), SortByName);
    printf("排序完成!\n");
    ShowContact(ps);
  }
}
