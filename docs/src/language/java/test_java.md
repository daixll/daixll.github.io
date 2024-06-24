# test/java

## org/dxl

<details><summary>ApplicationTests.java</summary>

```java
package org.dxl;

import jakarta.annotation.Resource;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.dxl.mapper.EmpMapper;
import org.dxl.pojo.Emp;

import java.util.List;

@SpringBootTest
class SpringbootWebMybatisCrudApplicationTests {

	@Resource
	EmpMapper empMapper;

	@Test
	void testGetEmpList(){
		List<Emp> list = empMapper.getEmpList();
		for (Emp e : list){
			System.out.println(e);
		}
	}
}
```
</details>

