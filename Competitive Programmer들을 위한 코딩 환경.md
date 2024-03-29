일반적으로 이 분야는 프로젝트의 규모가 파일 1개 정도 선에서 정리가 됩니다.
그래서 많은 기능을 제공하는 IDE를 사용하는 것은 어느 정도 소 잡는 칼로 닭 잡는 꼴이 됩니다.

따라서, 대부분의 사람들은 Code Editor을 이용합니다.

대표적으로는 Vim, Sublime Text 3, VS Code, Emacs, Atom등이 있습니다.
그럼에도 IDE를 사용하는 경우에는 Geany, Eclipse, CLion, Code::Blocks, XCode, Dev C++등이 있습니다. (Geany와 Code::Blocks, Dev C++은 IDE임에도 불구하고 상당히 가볍습니다.)

저는 Code::Blocks, XCode, VS Code를 오랫동안 사용해봤습니다.

* Code::Blocks는 안 예쁘고 셋팅이 어려워서 윈도우->맥으로 이동하면서 자연스럽게 버렸습니다.
* XCode는 매우 편리하지만, 컴파일러가 gcc가 아니라는 점, IDE라 무겁다는 점에서 포기했습니다.
* VS Code는 ~~XCode의 편리한 기능들이 간혹 없어서 불편하지만 하나씩 찾아서 기능을 넣고 있습니다.~~ 묻고 더블로 더 좋은 기능도 많아요 ㄸ

암튼, XCode는 전에 글([Xcode 사용자를 위한 C/C++ 이용법](https://mathsciforstudent.tistory.com/105))을 쓴 적이 있고 그래서
이번에는 VS Code의 셋팅에 관한 얘기들을 해보려 합니다.

## 다운 링크 찾기 귀찮아요
https://code.visualstudio.com/

## 이거 실행 안 돼요
### Window
저도 이건 안 써봐서 몰라요. https://usaco.guide/general/running-code-locally?lang=cpp#windows 여기 드가보세요.

### Mac
터미널을 들어갑시다. Command+Space 누르고 바로 검색하면 뜹니다.

1. XCode Command Line Tool을 설치합니다.
   * 처음이면 `xcode-select --install`라고 쓰고 엔터 눌러줘요.
   * 이미 설치했으면 설치 말고 업데이트 해야 하니깐 `softwareupdate -i -a` 요래 적어주고 엔터 눌러줘요.
2. [homebrew](https://brew.sh/) 드가서 적당히 깔아줘요.
3. 다시 터미널 드가서 `brew install gcc` 적고 엔터.
4. `g++-11 --version`(현재는 12)이라고 적고, 엔터치면 copyright 뭐시기 뜨면서 완료됐다고 알려줍니다.

## 컴파일 세팅

대충 VS Code 열고나면 왼쪽에 이런거 뜰거에요.

<img width="20" alt="스크린샷 2021-08-12 오후 7 17 11" src="https://user-images.githubusercontent.com/70815390/129180473-ad4d8488-bc48-42ca-bb71-d80102d2f501.png">
그 중에 이거 <img width="57" alt="스크린샷 2021-08-12 오후 7 18 30" src="https://user-images.githubusercontent.com/70815390/129180638-80ade85e-5090-4e6d-bdb6-0df67eff2a13.png">가 마켓인데, 앞으로 여기서 뭐 받으면 돼요.

그 중에서 우린 요 2개 받으면 됩니다.

<img width="408" alt="스크린샷 2021-08-12 오후 7 15 47" src="https://user-images.githubusercontent.com/70815390/129180307-c8f3b533-b3af-4883-9cd9-d6acf01ad775.png">

이런 것도 있으니 참고하세요
<img width="519" alt="스크린샷 2021-11-25 오후 11 15 05" src="https://user-images.githubusercontent.com/70815390/143457016-6234d706-6120-4f9e-89d6-e5500daf330c.png"> 
