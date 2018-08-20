package br.edu.ulbra.gestaovinhos.controller;

import br.edu.ulbra.gestaovinhos.input.UserInput;
import br.edu.ulbra.gestaovinhos.model.Role;
import br.edu.ulbra.gestaovinhos.model.User;
import br.edu.ulbra.gestaovinhos.repository.RoleRepository;
import br.edu.ulbra.gestaovinhos.repository.UserRepository;
import br.edu.ulbra.gestaovinhos.service.interfaces.SecurityService;
import br.edu.ulbra.gestaovinhos.service.interfaces.UserService;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

@Controller
@RequestMapping("/admin/usuario")
public class AdminUserController {
	@Autowired
	SecurityService securityService;
	@Autowired
	UserRepository userRepository;
	@Autowired
	UserService userService;
	@Autowired
	RoleRepository roleRepository;

	private ModelMapper mapper = new ModelMapper();

	@RequestMapping()
	public ModelAndView listaUsuarios() {
		ModelAndView mv = new ModelAndView("admin/usuario/lista");
		mv.addObject("userLogged", securityService.findLoggedInUser());

		if (securityService.findLoggedInUser() != null && securityService.findLoggedInUser().getRoles() != null) {
			for(Role p : securityService.findLoggedInUser().getRoles()){
				if (p.getName().equals("ROLE_ADMIN")) {
					mv.addObject("admin", true);
					break;
				}
				else {
					mv.addObject("admin", false);
				}
			}
		}

		List<User> usuarios = (List<User>) userRepository.findAll();
		mv.addObject("users", usuarios);
		return mv;
	}

	@GetMapping("/novo")
	public ModelAndView novoUsuarioForm(@ModelAttribute("user") UserInput user){
		List<Role> roles = (List<Role>)roleRepository.findAll();
		ModelAndView mv = new ModelAndView("admin/usuario/novo");
		mv.addObject("userLogged", securityService.findLoggedInUser());

		if (securityService.findLoggedInUser() != null && securityService.findLoggedInUser().getRoles() != null) {
			for(Role p : securityService.findLoggedInUser().getRoles()){
				if (p.getName().equals("ROLE_ADMIN")) {
					mv.addObject("admin", true);
					break;
				}
				else {
					mv.addObject("admin", false);
				}
			}
		}

		mv.addObject("roles", roles);
		mv.addObject("user", user);
		return mv;
	}

	@PostMapping("/novo")
	public String novoUsuario(UserInput userInput, RedirectAttributes redirectAttrs){
		User usuario = userRepository.findByUsername(userInput.getUsername());

		if (usuario != null) {
			redirectAttrs.addFlashAttribute("error", "Um usuário com esse email já está cadastrado.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		if (userInput.getPassword().length() == 0) {
			redirectAttrs.addFlashAttribute("error", "Uma senha deve ser informada.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		if (!userInput.getPassword().equals(userInput.getPasswordConfirm())) {
			redirectAttrs.addFlashAttribute("error", "Senha e confirmação de senha não são iguais.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/novo";
		}

		Role role = roleRepository.findOne(userInput.getIdRole());
		User user = mapper.map(userInput, User.class);
		Set<Role> roles = new HashSet<>();
		roles.add(role);
		user.setRoles(roles);
		userService.save(user);

		redirectAttrs.addFlashAttribute("success", "Usuário cadastrado com sucesso.");
		return "redirect:/admin/usuario";
	}

	@GetMapping("/{id}")
	public ModelAndView detalheUsuario(@PathVariable("id") Long idUsuario, RedirectAttributes redirectAttrs){
		User usuario = userRepository.findOne(idUsuario);

		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "O usuário solicitado não existe.");
			return new ModelAndView("redirect:/admin/usuario");
		}

		UserInput userInput = mapper.map(usuario, UserInput.class);

		Set<Role> userRoles = usuario.getRoles();
		if (userRoles.size() > 0){
			userInput.setIdRole(userRoles.iterator().next().getId());
		}

		List<Role> roles = (List<Role>)roleRepository.findAll();

		ModelAndView mv = new ModelAndView("admin/usuario/detalhe");
		mv.addObject("userLogged", securityService.findLoggedInUser());

		if (securityService.findLoggedInUser() != null && securityService.findLoggedInUser().getRoles() != null) {
			for(Role p : securityService.findLoggedInUser().getRoles()){
				if (p.getName().equals("ROLE_ADMIN")) {
					mv.addObject("admin", true);
					break;
				}
				else {
					mv.addObject("admin", false);
				}
			}
		}

		mv.addObject("roles", roles);
		mv.addObject("user", userInput);
		return mv;
	}

	@PostMapping("/{id}")
	public String salvarUsuario(@PathVariable("id") Long idUsuario, UserInput userInput, RedirectAttributes redirectAttrs) {
		User usuario = userRepository.findOne(idUsuario);

		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "Esse usuário não existe.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		User usuarioTest = userRepository.findByUsername(userInput.getUsername());
		if (usuarioTest != null && !usuario.getUsername().equals(usuarioTest.getUsername())) {
			redirectAttrs.addFlashAttribute("error", "Um usuário com esse email já está cadastrado.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		if (userInput.getPassword().length() != 0 && !userInput.getPassword().equals(userInput.getPasswordConfirm())) {
			redirectAttrs.addFlashAttribute("error", "Senha e confirmação de senha não são iguais.");
			redirectAttrs.addFlashAttribute("user", userInput);
			return "redirect:/admin/usuario/" + idUsuario;
		}

		usuario.setName(userInput.getName());
		usuario.setUsername(userInput.getUsername());
		if (userInput.getPassword().length() != 0) {
			usuario.setPassword(userInput.getPassword());
		}

		userService.save(usuario);

		redirectAttrs.addFlashAttribute("success", "Usuário alterado com sucesso.");
		redirectAttrs.addFlashAttribute("user", userInput);
		return "redirect:/admin/usuario/" + idUsuario;
	}

	@PostMapping("/{id}/resetSenha")
	public String resetarSenhaUsuario(@PathVariable("id") Long idUsuario){
		return "redirect:/admin/usuario/" + idUsuario;
	}

	@RequestMapping("/{id}/delete")
	public String deletarUsuario(@PathVariable("id") Long idUsuario, RedirectAttributes redirectAttrs) {
		User usuario = userRepository.findOne(idUsuario);
		if (usuario == null) {
			redirectAttrs.addFlashAttribute("error", "Não existe uma usuário com essa identificação.");
		} else {
			userRepository.delete(usuario);
			redirectAttrs.addFlashAttribute("success", "Usuário deletado com sucesso.");
		}

		return "redirect:/admin/usuario";
	}
}
