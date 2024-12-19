
# 프로젝트 실행 가이드

## 파일 설명

- **`mazesolution.h`**: BFS 알고리즘과 전역 변수의 선언을 포함합니다.
- **`mazesolution.c`**: BFS 알고리즘과 전역 변수의 정의를 포함합니다.
- **`main.c`**: 정적 또는 동적 라이브러리를 사용하여 BFS를 호출하고 결과를 출력합니다.
- **`main2.c`**: 런타임에 `libmyal.so`를 동적으로 로드하여 BFS를 호출합니다.
- **`libmyalstatic.a`**: BFS 함수와 전역 변수를 포함한 정적 라이브러리.
- **`libmyal.so`**: BFS 함수와 전역 변수를 포함한 공유 라이브러리.

---

## 실행 파일 생성 및 실행 방법

### 1. 정적 링크 실행 파일 (`static`)

정적 라이브러리를 사용하여 `static` 실행 파일을 생성합니다.

1. **컴파일**:

   ```bash
   gcc -o static main.o -L. -lmyalstatic
   ```

2. **실행**:

   ```bash
   ./static
   ```

3. **입력 예제**:

   ```
   5 5
   11111
   00001
   11111
   10000
   11111
   ```

4. **출력 예제**:

   ```
   17
   ```

---

### 2. 동적 링크 실행 파일 (`shared`)

공유 라이브러리를 사용하여 `shared` 실행 파일을 생성합니다.
1. **공유 라이브러리 생성**:

   ```bash
   gcc -fPIC -shared -o libmyal.so mazesolution.c
   ```

1. **컴파일**:

   ```bash
   gcc -o shared main.c -L. -lmyal
   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
      ```

2. **실행**:

   ```bash
   ./shared
   ```

3. **입력 예제**:

   ```
   5 5
   11111
   00001
   11111
   10000
   11111
   ```

4. **출력 예제**:

   ```
   17
   ```

---

### 3. 런타임 링크 실행 파일 (`runtime`)

`libmyal.so`를 런타임에 동적으로 로드하여 `runtime` 실행 파일을 생성합니다.


2. **컴파일**:

   ```bash
   gcc -rdynamic -o runtime main2.c -ldl
   ```

3. **실행**:

   ```bash
   ./runtime
   ```

4. **입력 예제**:

   ```
   Enter the size of the maze (n m):
   5 5
   Enter the maze (5 lines with 5 characters each):
   11111
   00001
   11111
   10000
   11111
   ```

5. **출력 예제**:

   ```
   Shortest path range: 17
   ```

---

