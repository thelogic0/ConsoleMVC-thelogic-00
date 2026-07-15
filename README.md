# ConsoleMVC-thelogic-00

반도체 시료 생산주문관리 시스템(SampleOrderSystem) 프로젝트의 미션 1 PoC — **MVC 스켈레톤 코드**.

Model / Controller / View 3계층 분리와, View → Controller → Model 단방향 의존을 코드 구조로 증명하는 것이 목적이다. 데이터 영속성(JSON)·CRUD 전체 기능은 별도 리포 `DataPersistence-thelogic-00`에서 다룬다.

## 구조

```
ConsoleMVC-thelogic-00/
├── Model/
│   ├── Sample.h              # Sample 데이터 구조체
│   └── SampleRepository.h/.cpp   # 메모리 내 시료 저장소
├── Controller/
│   └── SampleController.h/.cpp   # View 요청을 Model 호출로 위임
├── View/
│   └── ConsoleView.h/.cpp        # 콘솔 메뉴 루프, 입출력
└── main.cpp                      # ConsoleView 실행 진입점
```

네임스페이스: `ConsoleMVC::Model`, `ConsoleMVC::Controller`, `ConsoleMVC::View`

의존 방향(헤더 include 관계로 확인 가능):
- `Model/*.h`는 다른 계층을 include하지 않음
- `Controller/*.h`는 `Model`만 include
- `View/*.h`는 `Controller`만 include (Model 직접 참조 없음)

## 기능

- `[1]` 시료 등록 — 시료 ID / 이름 / 평균 생산시간 / 수율 입력, 재고 0으로 등록
- `[2]` 시료 목록 조회 — ID / 시료명 / 평균생산시간 / 수율 / 현재재고 표시
- `[0]` 종료

## 빌드 및 실행

Visual Studio 2022+ (C++20, x64) 기준.

```
ConsoleMVC-thelogic-00.slnx 열어서 빌드
또는
MSBuild ConsoleMVC-thelogic-00\ConsoleMVC-thelogic-00.vcxproj /p:Configuration=Debug /p:Platform=x64
```

실행 파일: `ConsoleMVC-thelogic-00\x64\Debug\ConsoleMVC-thelogic-00.exe`

콘솔 코드페이지는 실행 시 앱이 자동으로 UTF-8(`CP_UTF8`)로 설정하므로 별도 `chcp` 설정 없이 한글이 정상 출력된다.
