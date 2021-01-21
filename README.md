## TEAM IDO


  <img src="https://user-images.githubusercontent.com/50495214/105191630-a78b6400-5b7a-11eb-9d74-ed95e774e8e7.png" width="100">

아두이노의 발음에서 착안한 팀 이름


#### 멤버

- [김경훈](https://github.com/khoon-git)
- [김성희](https://github.com/xxunghee)
- 김자영
- [박효준](https://github.com/phj1450)


#### 수상 내역
- 🥇 전북대학교 컴퓨터공학부 작품경진대회 대상



## 안전지킴이(Safety Keeper)

### 프로젝트의 목적 & 필요성

  우리 주변에서 빈번하게 발생하는 화재, 침수 등의 사건을 줄이기 위해서는 '안전한 상태'를 만드는 것이 가장 중요하다. 올해(2020년) 발생한 사건들 중 집이 비어있을 때 발생한 사고들(*인천 라면 형제 화재 사고, 여름의 호우로 인한 피해, ...*)에 초점을 맞춰 집 밖에서 집 안의 안전을 관리할 수 있는 플랫폼의 필요성을 느꼈고, 편리한 사용과 쉬운 접근을 위해 어플리케이션 형태를 고안해냈다.



### 프로젝트의 배경

  이 프로젝트는 사고 발생 상황을 재현할 집, 각 위험 요소들의 위험 정도를 측정할 센서들, 어플리케이션 개발 툴을 필요로 한다. 어플리케이션과 각 센서의 통신은 아두이노 블루투스 모듈을 이용한 블루투스 통신으로 이루어진다.

 집 안에서 위험을 발생시킬 수 있는 경우는 가스 누출, 화재, 침수로 추렸고, 적용 범위를 넓히고자 미세먼지의 많고 적음을 알려주는 기능도 추가했다.
 

#### 사용한 센서 

- 가스 감지 센서

- 화염 감지 센서

- 수위 감지 센서

- 미세먼지 감지 센서

- 쿨링팬(실내 환기를 도움)

- 서보모터(창문과 연결해 실내 환기를 도움)

  

#### 사용한 개발 도구

- 아두이노 IDE

- 앱인벤터


#### 개발 기간
2020-11-23 ~ 11-24



### 프로젝트의 결과

- 어플리케이션 UI

  <center>
    <img src="https://user-images.githubusercontent.com/50495214/105189180-09969a00-5b78-11eb-9a15-e5e669910806.png" width="300">
  </center>



- 테스트 한 모형 집

  <center>
    <img src="https://user-images.githubusercontent.com/50495214/105189216-13200200-5b78-11eb-9b69-11e3579b9cf6.png" height="200">
  </center>

  

- 각 위험 상황 별 어플리케이션 UI

  - 미세먼지 나쁨 상태 

    <center>
      <img src="https://user-images.githubusercontent.com/50495214/105190023-ef10f080-5b78-11eb-9548-004470e7b2bb.png">
    </center>

    집 안에서 화장지로 먼지 발생, 어플리케이션의 미세먼지 항목에 나쁨 표시(회색 구름 아이콘)

    팬이 가동되고 창문을 열어 환기 진행

    

  - 침수

    <center>
      <img src="https://user-images.githubusercontent.com/50495214/105189286-27fc9580-5b78-11eb-9c2b-8ffab7b2acc9.png">
    </center>

    수위 감지 센서가 침수 감지, 어플리케이션의 침수 항목에 위험 표시

    

  - 화재

    <center>
      <img src="https://user-images.githubusercontent.com/50495214/105189299-2cc14980-5b78-11eb-96f2-c27b5f2db1d0.png">
    </center>

    불꽃 감지 센서가 불꽃 감지, 어플리케이션의 화재 항목에 위험 표시

    

  - 가스 누출

    <center>
      <img src="https://user-images.githubusercontent.com/50495214/105189305-2df27680-5b78-11eb-9e55-3c66a1211633.png">
    </center>

    가스 감지 센서가 가스 감지, 어플리케이션의 가스 누출 항목에 위험 표시

    팬이 가동되고 창문을 열어 환기 진행
