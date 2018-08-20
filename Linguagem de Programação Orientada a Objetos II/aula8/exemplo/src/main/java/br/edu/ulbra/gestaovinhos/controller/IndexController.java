package br.edu.ulbra.gestaovinhos.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class IndexController {

    @GetMapping("/")
    @PostMapping("/")
    public String index(){
        return "index";
    }

    @RequestMapping( "/tales")
    public  String tales(){
        return "tales";
    }

}
