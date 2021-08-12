일반적으로 이 분야는 프로젝트의 규모가 파일 1개 정도 선에서 정리가 됩니다.
그래서 많은 기능을 제공하는 IDE를 사용하는 것은 어느 정도 소 잡는 칼로 닭 잡는 꼴이 됩니다.

따라서, 대부분의 사람들은 Code Editor을 이용합니다.

대표적으로는 Vim, Sublime Text 3, VS Code, Emacs, Atom등이 있습니다.
그럼에도 IDE를 사용하는 경우에는 Geany, Eclipse, CLion, Code::Blocks, XCode, Dev C++등이 있습니다. (Geany와 Code::Blocks, Dev C++은 IDE임에도 불구하고 상당히 가볍습니다.)

저는 Code::Blocks, XCode, VS Code를 오랫동안 사용해봤습니다.

* Code::Blocks는 안 예쁘고 셋팅이 어려워서 윈도우->맥으로 이동하면서 자연스럽게 버렸습니다.
* XCode는 매우 편리하지만, 컴파일러가 gcc가 아니라는 점, IDE라 무겁다는 점에서 포기했습니다.
* VS Code는 XCode의 편리한 기능들이 간혹 없어서 불편하지만 하나씩 찾아서 기능을 넣고 있습니다.

암튼, XCode는 전에 글([Xcode 사용자를 위한 C/C++ 이용법](https://mathsciforstudent.tistory.com/105))을 쓴 적이 있고 그래서
이번에는 VS Code의 셋팅에 관한 얘기들을 해보려 합니다.

## 다운 링크 찾기 귀찮아요 응애
https://code.visualstudio.com/

## 이거 실행 안 돼요 응애
### Window
저도 이건 안 써봐서 몰라요. https://usaco.guide/general/running-code-locally?lang=cpp#windows 여기 드가보세요.

### Mac
터미널을 들어갑시다. Command+Space 누르고 바로 검색하면 뜹니다.

1. XCode Command Line Tool을 설치합니다. (XCode라고?! 걍 따라와봐요)

* `xcode-select --install`라고 쓰고 엔터 눌러줘요.
* 이미 설치했으면 설치 말고 업데이트 해야 하니깐
```
softwareupdate --list # 업데이트 목록 나열 
softwareupdate -i -a # 모든 업데이트 설치
```
요래 적어주고 엔터 눌러줘요.
2. [homebrew](https://brew.sh/) 드가서 적당히 야무지게 깔아줘요.
3. 다시 터미널 드가서 `brew install gcc` 적고 엔터.
4. `g++-11 --version`이라고 적고, 엔터치면 
현재 시점으로는 gcc 11 버전인데, 그때는 어떨지 모르니까 검색해서 밑에꺼 적당히 적어줘요.
