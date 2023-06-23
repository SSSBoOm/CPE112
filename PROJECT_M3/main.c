#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char Province[][32] = {
    "Bangkok",
    "Krabi",
    "Kanchanaburi",
    "Kalasin",
    "Kamphaeng Phet",
    "Khon Kaen",
    "Chanthaburi",
    "Chachoengsao",
    "Chonburi",
    "Chainat",
    "Chaiyaphum",
    "Chumphon",
    "Chiang Rai",
    "Chiang Mai",
    "Trang",
    "Trat",
    "Tak",
    "Nakhon Nayok",
    "Nakhon Pathom",
    "Nakhon Phanom",
    "Nakhon Ratchasima",
    "Nakhon Si Thammarat",
    "Nakhon Sawan",
    "Nonthaburi",
    "Narathiwat",
    "Nan",
    "Bueng Kan",
    "Buriram",
    "Pathum Thani",
    "Prachuap Khiri Khan",
    "Prachinburi",
    "Pattani",
    "Phra Nakhon Si Ayutthaya",
    "Phayao",
    "Phang Nga",
    "Phatthalung",
    "Phichit",
    "Phitsanulok",
    "Phetchaburi",
    "Phetchabun",
    "Phrae",
    "Phuket",
    "Maha Sarakham",
    "Mukdahan",
    "Mae Hong Son",
    "Yasothon",
    "Yala",
    "Roi Et",
    "Ranong",
    "Rayong",
    "Ratchaburi",
    "Lopburi",
    "Lampang",
    "Lamphun",
    "Loei",
    "Sisaket",
    "Sakon Nakhon",
    "Songkhla",
    "Satun",
    "Samut Prakan",
    "Samut Songkhram",
    "Samut Sakhon",
    "Sa Kaeo",
    "Saraburi",
    "Sing Buri",
    "Sukhothai",
    "Suphan Buri",
    "Surat Thani",
    "Surin",
    "Nong Khai",
    "Nong Bua Lamphu",
    "Ang Thong",
    "Amnat Charoen",
    "Udon Thani",
    "Uttaradit",
    "Uthai Thani",
    "Ubon Ratchathani",
};

typedef struct Person {
  char *name;          // Person Name
  int age;             // number
  int sex;             // 1 = male 2 = female
  int Province;        // Province ID
  int WorkAge;         // number
  struct Person *prev; // Previous Person
  struct Person *next; // Next Person
} Person;

typedef struct adjPerson {             
  int Salary;             // เงินเดือน
  struct Person *data;    // Person Data
  struct adjPerson *prev; // Prev Person In Section
  struct adjPerson *next; // Next Person In Section
} adjPerson;

typedef struct Section {
  char *name;                     // ชื่อแผนก
  struct adjPerson *adjTopPerson; // First Person in Section (Top)(LinkedList)
  struct Section *prev;
  struct Section *next;
} Section;

void printProvinceList() {
  printf("Province List\n");
  for (int i = 0; i < 77; i++) {
    printf("%d. %s\n", i, Province[i]);
  }
}

// Find Person
Person *FindPerson(Person **p) {
  if (*p == NULL) {
    return NULL;
  }
  char buffer[256];
  printf("Enter Person Name: ");
  scanf("%s", buffer);
  Person *temp = *p;
  while (temp != NULL) {
    if (strcmp(temp->name, buffer) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void ShowPersonDetail(Person **p) {
  Person *temp = FindPerson(p);
  if (temp == NULL) {
    printf("Person Not Found\n");
    return;
  }
  printf("Name: %s\n", temp->name);
  printf("Age : %d\n", temp->age);
  printf("Sex %s\n", temp->sex == 1   ? "Male"
                     : temp->sex == 2 ? "Female"
                                      : "Unknown");
  printf("Province: %s\n", Province[temp->Province]);
  printf("Work Age: %d\n", temp->WorkAge);
  return;
}
// Find Section
Section *FindSection(Section **s) {
  if (*s == NULL) {
    return NULL;
  }
  char buffer[256];
  printf("Enter Section Name: ");
  scanf("%s", buffer);
  Section *temp = *s;
  while (temp != NULL) {
    if (strcmp(temp->name, buffer) == 0) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

void ShowSection(Section **s) {
  if (*s == NULL) {
    return;
  }
  Section *temp = *s;
  if (temp == NULL) {
    printf("No Section\n");
    return;
  }
  while (temp != NULL) {
    printf("%s\n", temp->name);
    temp = temp->next;
  }
}

void ShowPerson(Person **p) {
  Person *temp = *p;
  if (temp == NULL) {
    printf("No Person\n");
    return;
  }
  while (temp != NULL) {
    printf("%s\n", temp->name);
    temp = temp->next;
  }
}

void ShowPersonInSection(Section **s) {
  // Find Section
  Section *temp = FindSection(s);
  if (temp == NULL) {
    printf("Section Not Found\n");
    return;
  }
  // Show Person
  adjPerson *tempAdj = temp->adjTopPerson;
  if (tempAdj == NULL) {
    printf("No Person In Section\n");
    return;
  }
  while (tempAdj != NULL) {
    printf("%s\n", tempAdj->data->name);
    tempAdj = tempAdj->next;
  }
}

// Insert Section Function
void InsertSection(Section **s) {
  char buffer[256];
  printf("\nEnter Section Name: ");
  scanf("%s", buffer);
  Section *newSection = (Section *)malloc(sizeof(Section));
  newSection->name = strdup(buffer);
  newSection->adjTopPerson = NULL;
  newSection->prev = NULL;
  newSection->next = NULL;

  if (*s == NULL) {
    *s = newSection;
  } else {
    Section *temp = *s;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newSection;
    newSection->prev = temp;
  }
  printf("-> Insert Section \"%s\" successfull!\n", buffer);
  return;
}

// Insert Person To Section After Insert Person Function
// For AdjPerson
void InsertPersonToSection(Section **s, Person *p) {
  // Find Section First
  // Loop Until Find Section
  // Then Insert Person to Section

  // Find Section
  // use do while
  // if temp == NULL
  // then loop again

  // Check Have Section
  if (*s == NULL) {
    printf("Try To Insert Section\n");
    return;
  }

  // check p
  if (p == NULL) {
    printf("Person Not Exist\n");
    return;
  }

  Section *temp = FindSection(s);
  do {
    if (temp == NULL) {
      printf("Section Not Found\n");
      temp = FindSection(s);
    }
  } while (temp == NULL);

  // กันเพิ่มคนเข้าแผนกซ้ำ
  adjPerson *ptr = temp->adjTopPerson;
  while (ptr != NULL) {
    if (ptr->data == p) {
      return;
    }
    ptr = ptr->next;
  }

  // Insert Person to Section

  // Create AdjPerson
  adjPerson *newAdjPerson = (adjPerson *)malloc(sizeof(adjPerson));
  printf("Enter Salary: ");
  scanf("%d", &newAdjPerson->Salary);
  newAdjPerson->data = p;
  newAdjPerson->next = NULL;
  newAdjPerson->prev = NULL;
  printf("Move person Success");
  // Check if Section is Empty
  if (temp->adjTopPerson == NULL) {
    temp->adjTopPerson = newAdjPerson;
    
  } else {
    // Find Last AdjPerson
    adjPerson *tempAdj = temp->adjTopPerson;
    while (tempAdj->next != NULL) {
      tempAdj = tempAdj->next;
    }
    tempAdj->next = newAdjPerson;
    newAdjPerson->prev = tempAdj;
  }
}

// Insert Person
Person *InsertPerson(Person **p, Section **s) {
  char buffer[256];
  int numbuffer;
  int knowprovince;
  Person *newPerson = (Person *)malloc(sizeof(Person));
  printf("Enter Person Name: ");
  scanf("%s", buffer);
  newPerson->name = strdup(buffer);
  do {
    printf("Enter Person Age: ");
    scanf("%d", &newPerson->age);
  } while (newPerson->age < 0 || newPerson->age > 100);
  printf("Enter Sex(1 For male and 2 for female): ");
  // do while loop for check input
  do {
    scanf("%d", &numbuffer);
    if (numbuffer != 1 && numbuffer != 2) {
      printf("Please Enter 1 or 2: ");
    }
  } while (numbuffer != 1 && numbuffer != 2);
  newPerson->sex = numbuffer;
  do {
    // if dont know province id
    printf("If you dont know Province ID Enter 77\n");
    printf("Enter Province ID: ");
    scanf("%d", &newPerson->Province);
    if (newPerson->Province == 77) {
      printProvinceList();
    }
  } while (newPerson->Province < 0 || newPerson->Province > 76);
  do {
    printf("Enter Work Age: ");
    scanf("%d", &newPerson->WorkAge);
  } while (newPerson->WorkAge < 0 || newPerson->WorkAge > 100);
  newPerson->prev = NULL;
  newPerson->next = NULL;
  if (*p == NULL) {
    *p = newPerson;
  } else {
    Person *temp = *p;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newPerson;
    newPerson->prev = temp;
  }

  if (*s != NULL) {
    InsertPersonToSection(s, newPerson);
    printf("Insert Person Success\n");
  }
  printf("Create Person Success\n");

  return newPerson;
}

void GetPersonOutFromSection(Section **s, Person **p) {
  // Find Section
  Section *temp = FindSection(s);
  if (temp == NULL) {
    printf("Section Not Found\n");
    return;
  }
  // Find Person
  Person *tempPerson = FindPerson(p);
  if (tempPerson == NULL) {
    printf("Person Not Found\n");
    return;
  }
  // Find AdjPerson
  adjPerson *tempAdj = temp->adjTopPerson;
  while (tempAdj != NULL) {
    if (tempAdj->data == tempPerson) {
      break;
    }
    tempAdj = tempAdj->next;
  }
  if (tempAdj == NULL) {
    printf("Person Not Found in Section\n");
    return;
  }
  // Delete AdjPerson
  if (tempAdj->prev == NULL) {
    temp->adjTopPerson = tempAdj->next;
  } else {
    tempAdj->prev->next = tempAdj->next;
  }
  if (tempAdj->next != NULL) {
    tempAdj->next->prev = tempAdj->prev;
  }
  // Free AdjPerson

  free(tempAdj);
  printf("Get Person Out From Section Success\n");
  return;
}

void RemoveSectionAndDeleteAllAdjPerson(Section **s) {
  if (*s == NULL) {
    return;
  }
  // Find Section
  Section *temp = FindSection(s);
  if (temp == NULL) {
    printf("Section Not Found\n");
    return;
  }
  // Delete All AdjPerson
  adjPerson *tempAdj = temp->adjTopPerson;
  while (tempAdj != NULL) {
    if (tempAdj->prev == NULL) {
      temp->adjTopPerson = tempAdj->next;
    } else {
      tempAdj->prev->next = tempAdj->next;
    }
    if (tempAdj->next != NULL) {
      tempAdj->next->prev = tempAdj->prev;
    }
    adjPerson *tempAdj2 = tempAdj;
    tempAdj = tempAdj->next;
    free(tempAdj2);
  }
  // Delete Section
  if (temp->prev == NULL) {
    *s = temp->next;
  } else {
    temp->prev->next = temp->next;
  }
  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }
  free(temp);
  printf("Remove Section Success\n");
  return;
}

void GetPersonOutAllSectionAndDeletePerson(Section **s, Person **p) {
  if (*p == NULL) {
    return;
  }
  // Find Person
  Person *tempPerson = FindPerson(p);
  if (tempPerson == NULL) {
    printf("Person Not Found\n");
    return;
  }
  // Find Section
  Section *tempSection = *s;
  while (tempSection != NULL) {
    // Find AdjPerson
    adjPerson *tempAdj = tempSection->adjTopPerson;
    while (tempAdj != NULL) {
      if (tempAdj->data == tempPerson) {
        break;
      }
      tempAdj = tempAdj->next;
    }
    if (tempAdj != NULL) {
      // Delete AdjPerson
      if (tempAdj->prev == NULL) {
        tempSection->adjTopPerson = tempAdj->next;
      } else {
        tempAdj->prev->next = tempAdj->next;
      }
      if (tempAdj->next != NULL) {
        tempAdj->next->prev = tempAdj->prev;
      }
      // Free AdjPerson
      free(tempAdj);
    }
    tempSection = tempSection->next;
  }
  // Delete Person
  if (tempPerson->prev == NULL) {
    *p = tempPerson->next;
  } else {
    tempPerson->prev->next = tempPerson->next;
  }
  if (tempPerson->next != NULL) {
    tempPerson->next->prev = tempPerson->prev;
  }
  free(tempPerson);
  printf("Get Person Out From All Section And Delete Person Success\n");
  return;
}

void EditSection(Section **s) {
  if (*s == NULL) {
    return;
  }
  // Find Section
  char buffer[256];
  Section *temp = FindSection(s);
  if (temp == NULL) {
    printf("Section Not Found\n");
    return;
  }
  // Edit Section
  printf("Enter Section Name (New): ");
  scanf("%s", buffer);
  // if empty string then skip
  if (buffer[0] != '\0') {
    // free and then use strdup
    free(temp->name);
    temp->name = strdup(buffer);
  }
  return;
}

// ยัง ขี้เกียจทำ
void EditPerson(Person **p) {
  if (*p == NULL) {
    return;
  }
  // Find Person
  char buffer[256];
  int int_buffer;
  Person *temp = FindPerson(p);
  if (temp == NULL) {
    printf("Person Not Found\n");
    return;
  }
  // Edit Person
  printf("1.Name\n2.Age\n3.Sex\n4.Province\n5.Work Age");
  printf("\n\nEnter Choice: ");
  scanf("%d", &int_buffer);
  if (int_buffer == 1) {
    printf("Enter Person Name (new): ");
    scanf("%s", buffer);
    // if empty string then skip
    if (buffer[0] != '\0') {
      // free and then use strdup
      free(temp->name);
      temp->name = strdup(buffer);
    }
  } else if (int_buffer == 2) {
    printf("Enter Person Work Age (new): ");
    scanf("%d", &int_buffer);
    while (int_buffer > 100) {
      printf("Enter Person Work Age(new): ");
      scanf("%d", &int_buffer);
    }
    temp->WorkAge = int_buffer;
  } else if (int_buffer == 3) {
    printf("Enter Person Sex (new): ");
    scanf("%d", &int_buffer);
    while (int_buffer > 2) {
      printf("Enter Person Sex (1or2): ");
      scanf("%d", &int_buffer);
    }
    temp->sex = int_buffer;
  } else if (int_buffer == 4) {
    do {
      // if dont know province id
      printf("If you dont know Province ID Enter 77\n");
      printf("Enter Province ID: ");
      scanf("%d", &int_buffer);
      if (int_buffer == 77) {
        printProvinceList();
      }
    } while (int_buffer < 0 || int_buffer > 76);
    temp->Province = int_buffer;

  } else if (int_buffer == 5) {
    printf("Enter Person Work Age (new): ");
    scanf("%d", &int_buffer);
    while (int_buffer > temp->age) {
      printf("Enter Person Work Age(new): ");
      scanf("%d", &int_buffer);
    }
    temp->WorkAge = int_buffer;
  }

  return;
}

void averageSection(Section *s) {
  if (s == NULL)
    return;

  Section *temp = s;
  int numSection = 0;
  float sumPerson = 0;
  // traverse find amount of section
  while (temp != NULL) {
    numSection++;
    temp = temp->next;
  }
  // traverse find amount of person and amount of person in section
  float *numPerson = malloc(sizeof(float) * numSection);
  temp = s;
  int i = 0;

  while (temp != NULL) {
    int num = 0;
    adjPerson *currPerson = temp->adjTopPerson;
    while (currPerson != NULL) {
      num++;
      sumPerson++;
      currPerson = currPerson->next;
    }
    numPerson[i] = num;
    i++;
    temp = temp->next;
  }

  i = 0;
  temp = s;
  if (sumPerson == 0) {
    printf("Person in Section Not Found\n");
    return;
  }
  // traverse show name of section, amount of person and percent
  while (temp != NULL) {
    printf("%s has %.0f or %.2f%%\n", temp->name, numPerson[i],
           numPerson[i] / sumPerson * 100);
    temp = temp->next;
    i++;
  }
}

void averageSex(Section *s) {
  if (s == NULL)
    return;

  Section *temp = s;
  float sumPerson = 0, male = 0, female = 0;
  // traverse find amount of person and gender of employer
  while (temp != NULL) {
    adjPerson *currPerson = temp->adjTopPerson;
    while (currPerson != NULL) {
      if ((currPerson->data)->sex == 1)
        male++;
      else
        female++;
      sumPerson++;
      currPerson = currPerson->next;
    }
    temp = temp->next;
  }
  if (sumPerson == 0) {
    printf("Person in Section Not Found\n");
    return;
  }
  // show amount of gender and percent
  printf("Male has %.0f or %.2f%%\nFemale has %.0f or %.2f%%\n", male,
         (male / sumPerson) * 100, female, (female / sumPerson) * 100);
}

void averageAge(Section *s) {
  if (s == NULL)
    return;
  Section *temp = s;
  float sumPerson = 0, sumAge = 0;
  // traverse find amount of person and age
  while (temp != NULL) {
    adjPerson *currPerson = temp->adjTopPerson;
    while (currPerson != NULL) {
      sumAge += (currPerson->data)->age;
      sumPerson++;
      currPerson = currPerson->next;
    }
    temp = temp->next;
  }
  if (sumPerson == 0) {
    printf("Person in Section Not Found\n");
    return;
  }
  // show average age
  printf("Average Age = %.2f\n", (sumAge / sumPerson));
}

void averageSalary(Section *s) {
  if (s == NULL)
    return;

  Section *temp = s;
  float sumPerson = 0, sumSalary = 0;
  // traverse find amount of person and salary
  while (temp != NULL) {
    adjPerson *currPerson = temp->adjTopPerson;
    while (currPerson != NULL) {
      sumSalary += currPerson->Salary;
      sumPerson++;
      currPerson = currPerson->next;
    }
    temp = temp->next;
  }
  if (sumPerson == 0) {
    printf("Person in Section Not Found\n");
    return;
  }
  // show average salary
  printf("Average Salary = %.2f\n", (sumSalary / sumPerson));
}

void LoadFilePerson(Person **p) {
  Person *ptr = *p;
  FILE *fp = fopen("person.txt", "r");
  if (fp == NULL) {
    printf("Load File Fail\n");
    return;
  }
  char buffer[128];
  while (1) {
    if (fscanf(fp, "%s", buffer) == EOF) {
      return;
    }

    Person *newPerson = (Person *)malloc(sizeof(Person));
    fscanf(fp, "%d %d %d %d", &newPerson->age, &newPerson->sex,
           &newPerson->Province, &newPerson->WorkAge);
    newPerson->name = strdup(buffer);
    newPerson->prev = NULL;
    newPerson->next = NULL;
    if (ptr == NULL) {
      (*p) = newPerson;
    } else {
      ptr->next = newPerson;
      newPerson->prev = ptr;
    }
    ptr = newPerson;
  }
  fclose(fp);
}

void LoadFileSection(Section **s, Person **p) {
  int num = 0, Salary;
  Section *ptrSection = *s;
  FILE *fp = fopen("section.txt", "r");
  if (fp == NULL) {
    printf("Load File Fail\n");
    return;
  }

  char buffer[256];
  while (1) {
    if (fscanf(fp, "%s", buffer) == EOF) {
      return;
    }

    Section *newSection = (Section *)malloc(sizeof(Section));
    fscanf(fp, "%d", &num);
    newSection->name = strdup(buffer);
    newSection->adjTopPerson = NULL;
    newSection->prev = NULL;
    newSection->next = NULL;
    for (int i = 0; i < num; i++) {
      fscanf(fp, "%s %d", buffer, &Salary);

      adjPerson *newAdjPerson = (adjPerson *)malloc(sizeof(adjPerson));
      newAdjPerson->Salary = Salary;

      Person *temp, *ptr = *p;
      while (ptr != NULL) {
        if (strcmp(ptr->name, buffer) == 0) {
          temp = ptr;
          break;
        }
        ptr = ptr->next;
      }

      newAdjPerson->data = temp;
      newAdjPerson->next = NULL;
      newAdjPerson->prev = NULL;

      if (newSection->adjTopPerson == NULL) {
        newSection->adjTopPerson = newAdjPerson;
      } else {
        adjPerson *tempAdj = newSection->adjTopPerson;
        while (tempAdj->next != NULL) {
          tempAdj = tempAdj->next;
        }
        tempAdj->next = newAdjPerson;
        newAdjPerson->prev = tempAdj;
      }
    }

    if (ptrSection == NULL) {
      (*s) = newSection;
    } else {
      ptrSection->next = newSection;
      newSection->prev = ptrSection;
    }
    ptrSection = newSection;
  }
  fclose(fp);
}

void WriteFilePerson(Person *p) {
  FILE *fp = fopen("person.txt", "w");
  Person *temp = p;
  while (temp != NULL) {
    fprintf(fp, "%s\n", temp->name);
    fprintf(fp, "%d %d %d %d\n", temp->age, temp->sex, temp->Province,
            temp->WorkAge);
    temp = temp->next;
  }
  fclose(fp);
}

void WriteFileSection(Section *s) {
  FILE *fp = fopen("section.txt", "w");
  Section *tempS = s;
  while (tempS != NULL) {
    if (tempS->adjTopPerson == NULL) {
      fprintf(fp, "%s\n0\n", tempS->name);
    } else {
      adjPerson *temp = tempS->adjTopPerson;
      int num = 0;
      while (temp != NULL) {
        num++;
        temp = temp->next;
      }
      temp = tempS->adjTopPerson;
      fprintf(fp, "%s\n%d\n", tempS->name, num);
      for (int i = 0; i < num; i++) {
        fprintf(fp, "%s %d\n", (temp->data)->name, temp->Salary);
        temp = temp->next;
      }
    }
    tempS = tempS->next;
  }
  fclose(fp);
}

void Menu(Person **p, Section **s) {
  int c;

  while (1) {
    printf("\n**************************** MAIN MENU "
           "****************************\n");
    printf("1. Insert Data Menu\n");
    printf("2. Edit Data Menu\n");
    printf("3. Delete Data Menu\n");
    printf("4. Show Data Menu\n");
    printf("5. Statistic Menu\n");
    printf("6. Clear Terminal\n\n");
    printf("Select Menu: ");
    scanf("%d", &c);

    if (c == 1) {
      printf("\n-=-=-=-=-=-=-=-=-=-=-=-= Insert Data Menu "
             "=-=-=-=-=-=-=-=-=-=-=-\n");
      printf("1. Insert New Person\n");
      printf("2. Insert New Section\n");
      printf("3. Assign Person (Already Created) to Section\n");
      printf("\n9. Back To Main Menu\n\n");

      printf("Select Menu: ");
      scanf("%d", &c);

      if (c == 1) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Insert New Person =-=-=-=-=-=-=-=-\n");
        InsertPerson(p, s);
      } else if (c == 2) {
        printf("\n-=-=-=-=-=-=-=-=-=-=-=-= Insert New Section "
               "=-=-=-=-=-=-=-=-=-=-=-\n");
        InsertSection(s);
      }

      else if (c == 3) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Assign Person (Already Created) to "
               "Section =-=-=-=-=-=-=-=-\n");
        InsertPersonToSection(s, FindPerson(p));
      }

      else if (c == 9) {
        continue;
      } else {
        printf("\n! [Invalid Menu] Please try again !\n");
        continue;
      }

    } else if (c == 2) {
      printf("\n-=-=-=-=-=-=-=-=-=-= Edit Data Menu =-=-=-=-=-=-=-=-\n");
      printf("1. Edit Person Data\n");
      printf("2. Edit Section\n");
      printf("\n9. Back To Main Menu\n\n");

      printf("Select Menu: ");
      scanf("%d", &c);

      if (c == 1) {
        // Edit Person Data
        printf("\n-=-=-=-=-=-=-=-=-=-= Edit Person Data =-=-=-=-=-=-=-=-\n");
        EditPerson(p);
      } else if (c == 2) {
        // Edit Section Name
        printf("\n-=-=-=-=-=-=-=-=-=-= Edit Section =-=-=-=-=-=-=-=-\n");
        EditSection(s);
      } else if (c == 9) {
        continue;
      } else {
        printf("\n! [Invalid Menu] Please try again !\n");
        continue;
      }
    }

    else if (c == 3) {
      printf("\n-=-=-=-=-=-=-=-=-=-= Delete Data Menu =-=-=-=-=-=-=-=-\n");
      printf("1. Delete Person From Section\n");
      printf("2. Delete Person\n");
      printf("3. Delete Section\n");
      printf("\n9. Back To Main Menu\n\n");

      printf("Select Menu: ");
      scanf("%d", &c);

      if (c == 1) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Delete Person from section "
               "=-=-=-=-=-=-=-=-\n");
        GetPersonOutFromSection(s, p);
      } else if (c == 2) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Delete Person =-=-=-=-=-=-=-=-\n");
        GetPersonOutAllSectionAndDeletePerson(s, p);
      } else if (c == 3) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Delete Section =-=-=-=-=-=-=-=-\n");
        RemoveSectionAndDeleteAllAdjPerson(s);
      } else if (c == 9) {
        continue;
      } else {
        printf("\n! [Invalid Menu] Please try again !\n");
        continue;
      }
    }

    else if (c == 4) {
      printf("\n-=-=-=-=-=-=-=-=-=-= Show Data Menu =-=-=-=-=-=-=-=-\n");
      printf("1. Show All Section\n");
      printf("2. Show Person in Section\n");
      printf("3. Show All Person\n");
      printf("4. Show Person Detail\n");
      printf("\n9. Back To Main Menu\n\n");

      printf("Select Menu: ");
      scanf("%d", &c);

      if (c == 1) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Show All Section =-=-=-=-=-=-=-=-\n");
        ShowSection(s);
      } else if (c == 2) {
        printf(
            "\n-=-=-=-=-=-=-=-=-=-= Show Person in Section =-=-=-=-=-=-=-=-\n");
        ShowPersonInSection(s);
      } else if (c == 3) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Show All Person =-=-=-=-=-=-=-=-\n");
        ShowPerson(p);
      } else if (c == 4) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Show Person Detail =-=-=-=-=-=-=-=-\n");
        // Show Person Detail By name
        ShowPersonDetail(p);
      } else if (c == 9) {
        continue;
      } else {
        printf("\n! [Invalid Menu] Please try again !\n");
        continue;
      }
    }

    else if (c == 5) {
      printf("\n-=-=-=-=-=-=-=-=-=-=-=-= Statistic Menu "
             "=-=-=-=-=-=-=-=-=-=-=-\n");
      printf("1. People in Section Information\n");
      printf("2. Gender Information\n");
      printf("3. Age Information\n");
      printf("4. Salary Information\n");
      printf("\n9. Back To Main Menu\n\n");

      printf("Select Menu: ");
      scanf("%d", &c);
      if (c == 1) {
        printf("\n-=-=-=-=-=-=-=-=-=-= People in Section Information "
               "=-=-=-=-=-=-=-=-\n");
        averageSection(*s);
      } else if (c == 2) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Gender Information =-=-=-=-=-=-=-=-\n");
        averageSex(*s);
      } else if (c == 3) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Age Information =-=-=-=-=-=-=-=-\n");
        averageAge(*s);
      } else if (c == 4) {
        printf("\n-=-=-=-=-=-=-=-=-=-= Salary Information =-=-=-=-=-=-=-=-\n");
        averageSalary(*s);
      }
    }

    else if (c == 6) {
      system("clear");
    }

    else {
      printf("\n! [Invalid Menu] Please try again !\n");
      continue;
    }

    WriteFilePerson(*p);
    WriteFileSection(*s);
  }
}

int main() {
  Person *p = NULL;
  Section *s = NULL;
  LoadFilePerson(&p);
  LoadFileSection(&s, &p);
  Menu(&p, &s);
}