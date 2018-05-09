package hello;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class BusinessController {


    @RequestMapping(value = "/init2", method = {RequestMethod.POST, RequestMethod.GET})
    public String index(@RequestParam("name")String t1, @RequestParam("time")String t2) {
        return "this is business." + (( null == t1 ) ? "t1" : t1) + " " + (( null == t2 ) ? "t2" : t2);
//        return "this is business." + Optional.ofNullable(t1).orElse("t1") + " " + Optional.ofNullable(t2).orElse("t2");
    }

}
