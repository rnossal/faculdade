package br.edu.ulbra.gestaovinhos.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/vinhos")
public class VinhoController {

    @RequestMapping("/listar")
    public String listaVinhos(){
        return "vinhos/listarVinhos";
    }

    @RequestMapping("/detalhe")
    public String detalheVinhos(){
        return "vinhos/listarVinhos";
    }


}
